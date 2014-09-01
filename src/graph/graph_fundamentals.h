#ifndef ILYOAN_ALROGITHMS_GRAPH_FUNDAMENTALS_H
#define ILYOAN_ALGORITHMS_GRAPH_FUNDAMENTALS_H

#include <vector>
using namespace std;

namespace graph
{

// An edge from `u` to `v`.
class Edge
{
public:
    Edge(int _u, int _v) : u(_u), v(_v) {}
public:
    int u;
    int v;
};


// An edge from `u` to `v` with weight `w`.
template<typename W>
class WEdge : public Edge
{
public:
    WEdge(int _u, int _v, W _w) : Edge(_u, _v), w(_w) {}
public:
    W w;
};


// A matrix representation of a directed weighted graph.
template<typedef W, W INF>
class WGraph
{
public:
    WGraph(int n) : g(vector<vector<int> >(n, vector<W>(n, INF))) {}
    void SetEdge(WEdge e) { SetWeight(e.u, w.v, e.w); }
    void SetWeight(int u, int v, W w) { g[u][v] = w; }
    void GetWeight(int u, int v) { return g[u][v]; }
    void IsINF(int u, int v) { return g[u][v] >= INF; }

public:
    vector<vector<W> > g;
};


// An adjacent representation of a directed graph.
class AdjGraph
{
public:
    AdjGraph(int n) : g(vector<vector<int> >(n)) {}
    int size() const { return g.size(); }
    int GetAdjCount(int u) const { return g[u].size(); }
    int GetAdjVertex(int u, int i) const { return g[u][i]; }
    void AddEdge(int u, int v) { g[u].push_back(v); }
public:
    vector<vector<int> > g;
};

}
#endif
