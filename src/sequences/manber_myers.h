#ifndef ILYOAN_ALGORITHMS_SEQUENCES_MANBER_MYERS_H
#define ILYOAN_ALGORITHMS_SEQUENCES_MANBER_MYERS_H

#include <vector>
using namespace std;

namespace sequences
{

class ManberMyers
{
public:
    vector<int> Solve(const string& str);
    vector<int> GetSuffixArray();
    vector<int> GetRank();
private:
    vector<int> pos;
    vector<int> prm;
};

} // namespace sequences

#endif
