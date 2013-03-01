#include "testSequences.h"


#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "../sequences/lis.h"
using namespace sequences;

TestResult testLISLen()
{
    TestResult result;
    bool isPass = true;

    const char* inFile  = "data/sequences_lis.in";
    const char* outFile = "data/sequences_lis_len.out";

    fstream finIn(inFile, fstream::in);
    fstream finOut(outFile, fstream::in);

    int T;
    finIn >> T;

    for (int t = 1; t <= T; t++) {
        int len;
        finIn >> len;
        vector<int> seq(len, 0);
        for (int i = 0; i < len; i++) finIn >> seq[i];
        int res = LISLen(seq);
        int ans;
        finOut >> ans;
        if (res != ans) {
            result.add(TestFailInfo(__FUNCTION__, t));
            isPass = false;
            goto END_OF_TEST;
        }
    }
END_OF_TEST:
    finIn.close();
    finOut.close();

    if (isPass) result.passCount++;
    return result;
}

TestResult testLISLexSmall()
{
    TestResult result;
    bool isPass = true;

    const char* inFile  = "data/sequences_lis.in";
    const char* outFile = "data/sequences_lis_lex_small.out";

    fstream finIn(inFile, fstream::in);
    fstream finOut(outFile, fstream::in);

    int T;
    finIn >> T;

    for (int t = 1; t <= T; t++) {
        int len;
        finIn >> len;
        vector<int> seq(len, 0);
        for (int i = 0; i < len; i++) finIn >> seq[i];
        vector<int> res = LIS(seq);
        int ansLen;
        finOut >> ansLen;
        vector<int> ans(ansLen);
        for (int i = 0; i < ansLen; i++) finOut >> ans[i];
        if (res != ans) {
            result.add(TestFailInfo(__FUNCTION__, t));
            isPass = false;
            goto END_OF_TEST;
        }
    }
END_OF_TEST:
    finIn.close();
    finOut.close();

    if (isPass) result.passCount++;
    return result;
}
TestResult testSequencesAll()
{
    vector<pair<string, TestFunction> > tests;
    tests.push_back(make_pair(
                "testLISLen",
                 testLISLen));
    tests.push_back(make_pair(
                "testLISLexSmall",
                 testLISLexSmall));

    return testThis(__FUNCTION__, tests, true);
}


