#ifndef ILYOAN_ALGORITHMS_TEST_TEST_H
#define ILYOAN_ALGORITHMS_TEST_TEST_H

#include <vector>
#include <string>
using namespace std;

class TestFailInfo
{
public:
	TestFailInfo(const string& tname, int tcase);
	TestFailInfo(const char* tname, int tcase);
	TestFailInfo(const string& tname, int tcase, int tseed);
	TestFailInfo(const char* tname, int tcase, int tseed);
public:
	string testName;
	int testCase;
	bool isRandomTest;
	int randomSeed;
};

class TestResult
{
public:
	TestResult();

	void add(const TestFailInfo& failInfo);
	void add(const TestResult& testResult);

public:
	int passCount;
	int failCount;
	vector<TestFailInfo> testFailInfos;
};

typedef TestResult (*TestFunction)();

TestResult testAll();
TestResult testThis(
		string testName,
		const vector<pair<string, TestFunction> >& tests,
		bool isLastDepth = false);

#endif
