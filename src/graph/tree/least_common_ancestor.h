#ifndef ILYOAN_ALGORITHM_GRAPH_TREE_LEAST_COMMON_ANCESTOR_H
#define ILYOAN_ALGORITHM_GRAPH_TREE_LEAST_COMMON_ANCESTOR_H

#include "range_minimum_query.h"

#include <vector>
using namespace std;

namespace graph
{

// Least Common Ancester(LCA) problem solver.
class LeastCommonAncestor
{
public:
	LeastCommonAncestor(const vector<int>& parents);
	int GetLeastCommonAncestor(int u, int v);
	int GetDistance(int u, int v);
private:
	void Traverse(int node, int depth);
private:
	RangeMinimumQuery<int> rmq;
	vector<vector<int> > child;
	vector<int> trip;
	vector<int> trip_index_of_node;
	vector<int> depth;
	vector<int> discover;
	vector<int> discover_to_node;
	int discover_count;
};

} // namespace graph

#endif //ILYOAN_ALGORITHM_GRAPH_TREE_LEAST_COMMON_ANCESTOR_H
