#include "manacher.h"

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

namespace sequences
{

string Manacher::Solve(const string& str)
{
	// preprocessing.
	// given string should not contain [^$#].
	string s;
	if (str.length()) {
		s = "^";
		for_each(str.begin(), str.end(), [&s](char c) { s += "#" + c; });
		s += "#$";
	} else {
		s = "^$";
	}
	int n = s.length();
	int c = 0, r = 0;
	table = vector<int>(n);
	for (int i = 1; i < n-1; ++i) {
		int ii = 2 * c - i;
		table[i] = (r > i) ? min(r - i, table[ii]) : 0;
		while (s[i + 1 + table[i]] == s[i - 1 - table[i]]) {
			++table[i];
		}
		if (i + table[i] > r) {
			c = i;
			r = i + table[i];
		}
	}

	int max_len = 0;
	int max_index = 0;
	for (int i = 1; i < n - 1; ++i) {
		if (table[i] > max_len) {
			max_len = table[i];
			max_index = i;
		}
	}

	return str.substr((max_index - 1 - max_len) / 2, max_len);
}

vector<int> Manacher::GetTable()
{
	return table;
}

} // namespace sequences
