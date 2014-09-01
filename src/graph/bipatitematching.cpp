#include "bipatitematching.h"


BipatiteMatching::BipatiteMatching(int _lsize, int _rsize)
    : lsize(_lsize),
      rsize(_rsize),
      g(lsize)
{}


void BipatiteMatching::AddEdge(int l, int r)
{
    g.AddEdge(l, r);
}


int BipatiteMatching::Solve()
{
    int res = 0;
    llink = vector<int>(lsize, -1);
    rlink = vector<int>(rsize, -1);
    for (int i = 0; i < lsize; ++i) {
        visit = vector<bool>(lsize, false);
        res += Augment(i);
    }
    return res;
}


bool BipatiteMatching::Augment(int u) {
    if (visit[u]) return false;
    visit[u] = true;
    for (int i = 0; i < g.GetAdjCount(u); ++i) {
        int v = g.GetAdjVertex(u, i);
        if (rlink[v] == -1 || Augment(rlink[v])) {
            llink[u] = v;
            rlink[v] = u;
            return true;
        }
    }
    return false;
}
