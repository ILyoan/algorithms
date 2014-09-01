#ifndef ILYOAN_ALGORITHMS_GRAPH_SCC_H
#define ILYOAN_ALGORITHMS_GRAPH_SCC_H

#include "graph_fundamentals.h"

#include <vector>
#include <stack>
using namespace std;

namespace graph
{

// Strongly Connected Component Solver.
class SCC
{
public:
    vector<int> Solve(const AdjGraph& g);
private:
    int Solve(const AdjGraph& g, int u);
    int di, fi, count;
    vector<int> id, d, f;
    stack<int> st;
};

};

#endif
