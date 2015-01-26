#include "range_minimum_query.h"

#include <vector>
#include <limits>
using namespace std;

namespace graph
{

template <typename T>
RangeMinimumQuery<T>::RangeMinimumQuery()
{
}

template <typename T>
RangeMinimumQuery<T>::RangeMinimumQuery(const vector<T>& _array)
{
	Initialize(_array);
}

template <typename T>
void RangeMinimumQuery<T>::Initialize(const vector<T>& _array)
{
	array = _array;
	range_min = vector<T>(4 * array.size());
	Initialize(1, 0, array.size() - 1);
}

template <typename T>
T RangeMinimumQuery<T>::Initialize(int node, int node_left, int node_right)
{
	if (node_left == node_right) {
		range_min[node] = array[node_left];
	} else {
		int m = (node_left + node_right) / 2;
		int l = Initialize(node * 2, node_left, m);
		int r = Initialize(node * 2 + 1, m + 1, node_right);
		range_min[node] = min(l, r);
	}
	return range_min[node];
}

template <typename T>
T RangeMinimumQuery<T>::Query(int left, int right)
{
	return Query(left, right, 1, 0, array.size() - 1);
}

template <typename T>
T RangeMinimumQuery<T>::Query(int left, int right, int node, int node_left, int node_right)
{
	// if the current node does not intersect with the query range, return MAX value.
	if (node_right < left || node_left > right) {
		return numeric_limits<T>::max();
	}
	// if the current node is included in the query range, return range_min of the current node.
	if (node_left >= left && node_right <= right) {
		return range_min[node];
	}
	// compute from left and right parts of the current node.
	int m = (node_left + node_right) / 2;
	int l = Query(left, right, node * 2, node_left, m);
	int r = Query(left, right, node * 2 + 1, m + 1, node_right);
	return min(l, r);
}

} // namespace graph
