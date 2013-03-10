#include "test.h"

#include "testMath.h"
#include "testSequences.h"

#include <cstdlib>
#include <cstdio>

TestFailInfo::TestFailInfo(const string& tname, int tcase)
    : testName(tname)
    , testCase(tcase)
    , isRandomTest(false)
    , randomSeed(0)
{
}

TestFailInfo::TestFailInfo(const char* tname, int tcase)
    : testName(tname)
    , testCase(tcase)
    , isRandomTest(false)
    , randomSeed(0)
{
}

TestFailInfo::TestFailInfo(const string& tname, int tcase, int seed)
    : testName(tname)
    , testCase(tcase)
    , isRandomTest(true)
    , randomSeed(seed)
{
}

TestFailInfo::TestFailInfo(const char* tname, int tcase, int seed)
    : testName(tname)
    , testCase(tcase)
    , isRandomTest(true)
    , randomSeed(seed)
{
}

TestResult::TestResult() 
    : passCount(0)
    , failCount(0)
{
}

void TestResult::add(const TestFailInfo& failInfo)
{
    this->failCount += 1;
    this->testFailInfos.push_back(failInfo);
}

void TestResult::add(const TestResult& testResult)
{
    this->passCount += testResult.passCount;
    this->failCount += testResult.failCount;

    this->testFailInfos.insert(this->testFailInfos.end(), 
            testResult.testFailInfos.begin(),
            testResult.testFailInfos.end());
}


TestResult testAll()
{
    vector<pair<string, TestFunction> > tests;
    tests.push_back(make_pair("testMathAll", testMathAll));
    tests.push_back(make_pair("testSequencesAll", testSequencesAll));

    return testThis("testAll", tests);
}

TestResult testThis(
        string testName, 
        const vector<pair<string, TestFunction> >& tests,
        bool isLastDepth)
{
    TestResult resAll;
    
    printf("\n%s - START\n\n", testName.c_str());

    for (int i = 0; i < tests.size(); i++) {
        string name = tests[i].first;
        TestFunction test = tests[i].second;
        
        if (isLastDepth) {
            printf("TEST: %s - ", name.c_str());
        }
        TestResult res = (*test)();
        if (isLastDepth) {
            printf("pass: %d, fail: %d\n", res.passCount, res.failCount);
        }
        resAll.add(res);
    }

    printf("\n%s - END - pass: %d, fail: %d\n\n", 
            testName.c_str(),
            resAll.passCount,
            resAll.failCount);

    return resAll;
}

int main()
{
    printf("====================\n");
    printf("     TEST START\n");
    printf("====================\n");

    testAll();

    return 0;
}


