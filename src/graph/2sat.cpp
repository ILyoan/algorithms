#include "scc.h"
#include "2sat.h"

#include <algorithm>
using namespace std;

// Constructor of 2SAT solver.
TwoSAT::TwoSAT(int n) : g(2*n)
{ }

void TwoSAT::UorV(int u, int v)
{
    NotUtoV(u, v);
    NotUtoV(v, u);
}

void TwoSAT::UtoV(int u, int v)
{
    g.AddEdge(2*u, 2*v);
}

void TwoSAT::NotUtoV(int u, int v)
{
    g.AddEdge(2*u+1, 2*v);
}

void TwoSAT::UtoNotV(int u, int v)
{
    g.AddEdge(2*u, 2*v+1);
}

void TwoSAT::NotUtoNotV(int u, int v)
{
    g.AddEdge(2*u+1, 2*v+1);
}

// Solve 2-SAT problem.
vector<bool> TwoSAT::Solve()
{
    // Find SCC of given graph.
    SCC scc;
    vector<int> sccId = scc.Solve(g);
    
    // number of variables.
    int n = g.size() / 2;

    // if a variable and its complement are in the same component,
    // than there is no solution.
    for (int i = 0; i < 2*n; i += 2) {
        if (sccId[i] == sccId[i+1]) {
            return vector<bool>();
        }
    }
    // Topological order of the SCC.
    vector<pair<int, int> > torder;
    for (int i = 0; i < 2*n; ++i) {
        torder.push_back(make_pair(sccId[i], i));
    }
    // Topological order is inverse of scc id.
    sort(torder.rbegin(), torder.rend());

    // Assign
    vector<bool> res(n);
    vector<bool> visit(n ,false);
    for (int i = 0; i < 2*n; ++i) {
        int u = torder[i].second;
        int v = u / 2;
        bool is = u % 2;
        if (visit[v]) {
            continue;
        }
        res[v] = is;
        visit[v] = true;
    }
    return res;
}
