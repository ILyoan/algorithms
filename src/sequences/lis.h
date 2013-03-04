#ifndef ILYOAN_ALGORITHMS_SEQUENCES_LIS_H
#define ILYOAN_ALGORITHMS_SEQUENCES_LIS_H

#include <vector>
using namespace std;

namespace sequences
{

// Get the length of Logest Increasing Subequence of vector `A` in O(n^2)
int LISLen(const vector<int>& A);

// Get Logest Increasing Subequence of vector `A` in O(n^2).
// Return the lexicographically smallest LIS.
vector<int> LIS(const vector<int>& A);

// Get the length of Logest Increasing Subequence of vector `A` in O(n log n)
int FastLISLen(const vector<int>& A);

// Get Logest Increasing Subequence of vector `A` in O(n log n).
// Return the lexicographically smallest LIS.
vector<int> FastLIS(const vector<int>& A);

} // namespace sequences

#endif
