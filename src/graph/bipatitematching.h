#ifndef ILYOAN_ALGORITHMS_GRAPH_BIPATITE_MATCHING_H
#define ILYOAN_ALGORITHMS_GRAPH_BIPATITE_MATCHING_H

#include "graph_fundamentals.h"

namespace graph
{

// Bipatite matching solver
class BipatiteMatching
{
public:
    BipatiteMatching(int lsize, int rsize);
    void AddEdge(int l, int r);
    int Solve();
    vector<int> GetLMatching();
    vector<int> GetRMatching();
private:
    bool Augment(int u);
    int lsize;
    int rsize;
    vector<int> llink;
    vector<int> rlink;
    vector<bool> visit;
    AdjGraph g;
};

}

#endif
