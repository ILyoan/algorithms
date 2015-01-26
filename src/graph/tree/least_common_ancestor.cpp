#include "least_common_ancestor.h"

#include <vector>
using namespace std;

namespace graph
{

LeastCommonAncestor::LeastCommonAncestor(const vector<int>& parents)
		: child(parents.size()),
		  depth(parents.size()),
		  trip_index_of_node(parents.size()),
		  discover(parents.size()),
		  discover_to_node(parents.size()),
		  discover_count(0)
{
	int root_node = 0;
	for (int i = 0; i < parents.size(); ++i) {
		int p = parents[i];
		if (p != -1) {
			child[p].push_back(i);
		} else {
			root_node = i;
		}
	}
	Traverse(root_node, 0);
	rmq.Initialize(trip);
}

void LeastCommonAncestor::Traverse(int node, int d)
{
	discover[node] = discover_count++;
	discover_to_node[discover[node]] = node;
	depth[node] = d;
	trip_index_of_node[node] = trip.size();
	trip.push_back(discover[node]);

	for (int i = 0; i < child[node].size(); ++i) {
		Traverse(child[node][i], d + 1);
		trip.push_back(discover[node]);
	}
}

int LeastCommonAncestor::GetLeastCommonAncestor(int u, int v)
{
	int ui = trip_index_of_node[u];
	int vi = trip_index_of_node[v];
	if (ui > vi) swap(ui, vi);
	int lca_discover = rmq.Query(ui, vi);
	int lca = discover_to_node[lca_discover];
	return lca;
}

int LeastCommonAncestor::GetDistance(int u, int v)
{
	int lca = GetLeastCommonAncestor(u, v);
	return depth[u] + depth[v] - 2 * depth[lca];
}

} // namespace graph.

