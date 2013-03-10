#include <set>
#include <vector>
#include <algorithm>
using namespace std;

namespace sequences
{

// Get the length of Logest Increasing Subequence of vector `A` in O(n^2)
int LISLen(const vector<int>& A)
{
    int res = 0;
    int n = A.size();
    vector<int> len(n);
    for (int i = n-1; i >= 0; i--) {
        len[i] = 1;
        for (int j = i + 1; j < n; j++) {
            if (A[i] < A[j]) len[i] = max(len[i], len[j] + 1);
        }
        res = max(res, len[i]);
    }
    return res;
}

// Get Logest Increasing Subequence of vector `A` in O(n^2).
// Return the lexicographically smallest LIS.
vector<int> LIS(const vector<int>& A)
{
    int n = A.size();
    int maxLen = 0;
    int maxLenStartIndex = 0;
    vector<int> len(n);
    vector<int> link(n);
    for (int i = n-1; i >= 0; i--) {
        len[i] = 1;
        link[i] = -1;
        for (int j = i + 1; j < n; j++) {
            if (A[i] < A[j]) {
                if (len[i] < len[j] + 1 
                        || len[i] == len[j] + 1 && A[link[i]] > A[j]) {
                    len[i] = len[j] + 1;
                    link[i] = j;
                }
            }
        }
        if (maxLen < len[i] 
                || maxLen == len[i] && A[maxLenStartIndex] > A[i]) {
            maxLen = len[i];
            maxLenStartIndex = i;
        }
    }
    vector<int> res;
    int cur = maxLenStartIndex;
    do {
        res.push_back(A[cur]);
        cur = link[cur];
    } while (cur != -1);
    return res;
}

// Get the length of Logest Increasing Subequence of vector `A` in O(n log n)
int FastLISLen(const vector<int>& A)
{
    int n = A.size();
    int maxLen = 0;
    vector<int> minLast(n);
    for (int i = 0; i < n; i++) {
        vector<int>::iterator pos = lower_bound(
                minLast.begin(), minLast.begin() + maxLen, A[i]);
        int lisLen = pos - minLast.begin();
        if (lisLen + 1> maxLen || minLast[lisLen] > A[i]) {
            minLast[lisLen] = A[i];
        }
        maxLen = max(maxLen, lisLen + 1);
    }
    return maxLen;
}



// Get Logest Increasing Subequence of vector `A` in O(n^2).
// Return the lexicographically smallest LIS.
struct LISNode {
    int n;
    LISNode* p;
    set<pair<int, LISNode*> > c;
};
static void go1(int depth, LISNode* node, LISNode*& maxLast, int& maxDepth)
{
    if (depth > maxDepth) {
        maxDepth = depth;
        maxLast = node;
    }
    set<pair<int, LISNode*> >::iterator it = node->c.begin();
    while (it != node->c.end()) {
        go1(depth + 1, it++->second, maxLast, maxDepth);
    }
}
static void go2(LISNode* root, LISNode* cur, vector<int>& res) 
{
    if (cur == root) return;
    go2(root, cur->p, res);
    res.push_back(cur->n);
}
vector<int> FastLIS(const vector<int>& A)
{
    int n = A.size();
    int maxLen = 0;
    vector<int> minLast(n, 0);
    vector<int> minLastIdx(n, 0);
    vector<bool> updated(n, false);
    vector<LISNode> nodes(n);
    LISNode root;
    for (int i = 0; i < n; i++) {
        LISNode* node = &nodes[i];
        node->n = A[i];
        vector<int>::iterator pos = lower_bound(
                minLast.begin(), minLast.begin() + maxLen, A[i]);
        int lisLen = pos - minLast.begin();
        if (lisLen + 1 > maxLen 
                || minLast[lisLen] > A[i]
                || lisLen > 0 && updated[lisLen-1] && minLast[lisLen] == A[i]) {
            minLast[lisLen] = A[i];
            minLastIdx[lisLen] = i;
            updated[lisLen] = true;
            if (lisLen > 0) updated[lisLen-1] = false;
            node->p = lisLen ? &nodes[minLastIdx[lisLen-1]] : &root;
            node->p->c.insert(make_pair(node->n, node));
        }
        maxLen = max(maxLen, lisLen + 1);
    }
    vector<int> res;
    LISNode* maxLast = NULL;
    int maxDepth = 0;
    go1(0, &root, maxLast, maxDepth);
    go2(&root, maxLast, res);
    return res;
}

} // namespace sequences
