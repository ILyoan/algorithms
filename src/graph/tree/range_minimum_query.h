#ifndef ILYOAN_ALGORITHMS_GRAPH_TREE_RANGE_MINIMUM_QUERY_H
#define ILYOAN_ALGORITHMS_GRAPH_TREE_RANGE_MINIMUM_QUERY_H

#include <vector>
using namespace std;

namespace graph
{

// Range Minimum Query(RMQ) problem solver.
template <typename T>
class RangeMinimumQuery
{
public:
	RangeMinimumQuery();
	RangeMinimumQuery(const vector<T>& array);
	void Initialize(const vector<T>& array);
	T Query(int left, int right);
private:
	T Initialize(int node, int node_left, int node_right);
	T Query(int left, int right, int node, int node_left, int node_right);
private:
	vector<T> array;
	vector<T> range_min;
};

} // namespace graph

#endif // ILYOAN_ALGORITHMS_GRAPH_TREE_RANGE_MINIMUM_QUERY_H

