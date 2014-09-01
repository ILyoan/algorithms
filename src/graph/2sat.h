#ifndef ILYOAN_ALGORITHMS_GRAPH_2SAT_H
#define ILYOAN_ALGORITHMS_GRAPH_2SAT_H

#include "graph_fundamentals.h"

#include <vector>
using namespace std;

namespace graph
{

// 2-SAT Solver.
class TwoSAT
{
public:
    TwoSAT(int n);
    void UorV(int u, int v);
    void UtoV(int u, int v);
    void NotUtoV(int u, int v);
    void UtoNotV(int u, int v);
    void NotUtoNotV(int u, int v);
    vector<bool> Solve();
private:
    AdjGraph g;
};

};

#endif
