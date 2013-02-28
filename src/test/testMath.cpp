#include "testMath.h"

#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "../math/polynomial.h"
#include "../math/karatsuba.h"
#include "../math/fft.h"
using namespace math::polynomial;

TestResult testMathPolynomialBaseMultiply()
{
	TestResult result;
	bool isPass = true;

	const char* inFile  = "data/math_polynomial_multiply.in";
	const char* outFile = "data/math_polynomial_multiply.out";

	fstream finIn(inFile, fstream::in);
	fstream finOut(outFile, fstream::in);
	
	// number of test cases
	int T;
	finIn >> T;

	// This implementation is too naive so we will go to at most 10th 
	// test case.
	if (T > 10) T = 10;
	for (int t = 1; t <= T; t++) {
		// length of input
		int alen, blen;
		finIn >> alen >> blen;
		vector<int> a(alen, 0), b(blen, 0);
		for (int i = 0; i < alen; i++) finIn >> a[i];
		for (int i = 0; i < blen; i++) finIn >> b[i];
		
		vector<int> c = multiply(a, b);
		trim(c);
		
		for (int i = 0; i < c.size(); i++) {
			int tmp;
			finOut >> tmp;
			if (c[i] != tmp) {
				result.add(TestFailInfo(__FUNCTION__, t));
				isPass = false;
				goto END_OF_TEST;
			}
		}
	}

	finIn.close();
	finOut.close();

END_OF_TEST:
	if (isPass) result.passCount++;
	return result;
}

TestResult testMathPolynomialKaratsuba()
{
	TestResult result;
	bool isPass = true;

	const char* inFile  = "data/math_polynomial_multiply.in";
	const char* outFile = "data/math_polynomial_multiply.out";

	fstream finIn(inFile, fstream::in);
	fstream finOut(outFile, fstream::in);
	
	// number of test cases
	int T;
	finIn >> T;

	for (int t = 1; t <= T; t++) {
		// length of input
		int alen, blen;
		finIn >> alen >> blen;
		vector<int> a(alen, 0), b(blen, 0);
		for (int i = 0; i < alen; i++) finIn >> a[i];
		for (int i = 0; i < blen; i++) finIn >> b[i];
		
		vector<int> c = karatsuba(a, b);
		trim(c);
		
		for (int i = 0; i < c.size(); i++) {
			int tmp;
			finOut >> tmp;
			if (c[i] != tmp) {
				result.add(TestFailInfo(__FUNCTION__, t));
				isPass = false;
				goto END_OF_TEST;
			}
		}
	}

	finIn.close();
	finOut.close();

END_OF_TEST:
	if (isPass) result.passCount++;
	return result;
}

TestResult testMathPolynomialFFT()
{
	TestResult result;
	bool isPass = true;

	const char* inFile  = "data/math_polynomial_multiply.in";
	const char* outFile = "data/math_polynomial_multiply.out";

	fstream finIn(inFile, fstream::in);
	fstream finOut(outFile, fstream::in);
	
	// number of test cases
	int T;
	finIn >> T;

	for (int t = 1; t <= T; t++) {
		// length of input
		int alen, blen;
		finIn >> alen >> blen;
		vector<int> a(alen, 0), b(blen, 0);
		for (int i = 0; i < alen; i++) finIn >> a[i];
		for (int i = 0; i < blen; i++) finIn >> b[i];
		
		FFT fft = FFT::createFFT(a,b);
		vector<int> c = fft.c;
		trim(c);
		
		for (int i = 0; i < c.size(); i++) {
			int tmp;
			finOut >> tmp;
			if (c[i] != tmp) {
				result.add(TestFailInfo(__FUNCTION__, t));
				isPass = false;
				goto END_OF_TEST;
			}
		}
	}

	finIn.close();
	finOut.close();

END_OF_TEST:
	if (isPass) result.passCount++;
	return result;
}


TestResult testMathPolynomialAll()
{
	vector<pair<string, TestFunction> > tests;
	tests.push_back(make_pair(
				"testMathPolynomialBaseMultiply",
				 testMathPolynomialBaseMultiply));
	tests.push_back(make_pair(
				"testMathPolynomialKaratsuba",
				 testMathPolynomialKaratsuba));
	tests.push_back(make_pair(
				"testMathPolynomialFFT",
				 testMathPolynomialFFT));

	return testThis(__FUNCTION__, tests, true);
}

TestResult testMathAll()
{
	vector<pair<string, TestFunction> > tests;
	tests.push_back(make_pair(
				"testMathPolynomialAll",
				 testMathPolynomialAll));

    return testThis(__FUNCTION__, tests);
}

