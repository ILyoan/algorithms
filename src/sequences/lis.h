#ifndef ILYOAN_ALGORITHMS_SEQUENCES_LIS_H
#define ILYOAN_ALGORITHMS_SEQUENCES_LIS_H

#include <vector>
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

} // namespace sequences

#endif
