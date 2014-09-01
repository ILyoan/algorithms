#include "scc.h"

// Solve SCC problem by Tarjan's algorithm.
vector<int> SCC::Solve(const AdjGraph& g)
{
    count = di = fi = 0;
    id = d = f = vector<int>(g.size(), -1);
    for (int i = 0; i < g.size(); ++i) {
        if (d[i] == -1) {
            Solve(g, i);
        }
    }
    return id;
}

int SCC::Solve(const AdjGraph& g, int u) {
    int low = d[u] = di++;
    st.push(u);
    for (int i = 0; i < g.GetAdjCount(u); ++i) {
        int v = g.GetAdjVertex(u, i);
        if (d[v] == -1) {
            low = min(low, Solve(g, v));
        } else if (f[v] == -1) {
            low = min(low, d[v]);
        }
    }
    if (low == d[u]) {
        while (true) {
            int v = st.top();
            st.pop();
            id[v] = count;
            if (u == v) {
                break;
            }
        }
        ++count;
    }
    f[u] = fi++;
    return low;
}

