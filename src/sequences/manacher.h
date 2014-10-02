#ifndef ILYOAN_ALGORITHMS_SEQUENCES_MANACHER_H
#define ILYOAN_ALGORITHMS_SEQUENCES_MANACHER_H

#include <string>
#include <vector>
using namespace std;

namespace sequences
{

class Manacher
{
public:
	// Find longest substring palindrome of given string.
	string Solve(const string& str);
	vector<int> GetTable();
private:
	vector<int> table;
};

} // namespace sequences

#endif
