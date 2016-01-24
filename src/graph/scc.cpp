#include "scc.h"

// Solve SCC problem by Tarjan's algorithm.
vector<int> SCC::Solve(const AdjGraph& g)
{
	int n = g.size();

	_di = 0;
	_scc_count = 0;	
	_scc_ids = vector<int>(n);
	_discovers = vector<int>(n, -1);
	_is_in_stack = vector<bool>(n);

    for (int u = 0; u < n; ++u) {
        if (_discovers[u] == -1) {
            Solve(g, u);
        }
    }
    return _scc_ids;
}

int SCC::Solve(const AdjGraph& g, int u) {
    int low = _discovers[u] = _di++;
	_stack.push(u);
	_is_in_stack[u] = true;
    for (int i = 0; i < g.GetAdjCount(u); ++i) {
        int v = g.GetAdjVertex(u, i);
        if (_discovers[v] == -1) {
            low = min(low, Solve(g, v));
        } else if ((_is_in_stack[v]) {
            low = min(low, _discovers[v]);
        }
    }
    if (low == _discovers[u]) {
        while (true) {
            int v = _stack.top();
			_stack.pop();
			_is_in_stack[v] = false;
			_scc_ids[v] = _scc_count;
            if (u == v) {
                break;
            }
        }
        ++_scc_count;
    }
    return low;
}

