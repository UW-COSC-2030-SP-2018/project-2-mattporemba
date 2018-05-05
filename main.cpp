// Matt Poremba
// COSC 2030
// 23 April 2018
// Project 2

#include <iostream>
#include <vector>
#include <algorithm>
#include "vectorFunctions.h"
#include "bloom.h"

using namespace std;

// Creates a vector of a specified size filled with random numbers.
vector<int> randomVector(int size);

int main()
{
	// Create an array to hold test vectors,
	// initialize to hardcoded size and number of vectors
	const int numOfVectors = 1000;
	const int size = 100;
	vector<int> testVectors[numOfVectors];
	vector<int> testVectorsSTL[numOfVectors];
	for (int i = 0; i < numOfVectors; i++) {
		vector<int> temp = randomVector(size);
		testVectors[i] = temp;
		testVectorsSTL[i] = temp;
	}
	// Create an empty and single vector for testing corner cases
	vector<int> corner1;
	vector<int> corner2;
	corner2.push_back(1);

	// Testing qSort()
	int succeed(0), fail(0);
	cout << "TESTING qSort():" << endl;
	for (int i = 0; i < numOfVectors; i++) {
		qSort(testVectors[i], 0, size - 1);
		sort(testVectorsSTL[i].begin(), testVectorsSTL[i].end());
		if (testVectors[i] == testVectorsSTL[i]) {
			succeed++;
		}
		else {
			fail++;
		}
	}
	cout << "Number of times qSort() succeeded: " << succeed << endl;
	cout << "Number of times qSort() failed: " << fail << endl;

	// Testing biSearch
	cout << "\n\nTESTING biSearch():" << endl;
	succeed = 0;
	fail = 0;
	for (int i = 0; i < numOfVectors; i++) {
		int findNumber = testVectors[i].at(rand() % size);
		int foundIndex = biSearch(testVectors[i], 0, size - 1, findNumber);
		if (testVectors[i][foundIndex] == findNumber) {
			succeed++;
		}
		else {
			fail++;
		}
	}
	cout << "Number of times biSearch() succeeded: " << succeed << endl;
	cout << "Number of times biSearch() failed: " << fail << endl;

	// Reset test vectors by randomizing them again,
	// initialize to hardcoded size and number of vectors
	for (int i = 0; i < numOfVectors; i++) {
		vector<int> temp = randomVector(size);
		testVectors[i] = temp;
		testVectorsSTL[i] = temp;
	}

	//Testing mSort()
	cout << "\n\nTESTING mSort():" << endl;
	succeed = 0;
	fail = 0;
	for (int i = 0; i < numOfVectors; i++) {
		mSort(testVectors[i]);
		sort(testVectorsSTL[i].begin(), testVectorsSTL[i].end());
		if (testVectors[i] == testVectorsSTL[i]) {
			succeed++;
		}
		else {
			fail++;
		}
	}
	cout << "Number of times qSort() succeeded: " << succeed << endl;
	cout << "Number of times qSort() failed: " << fail << endl;



	return 0;
}

vector<int> randomVector(int size)
{
	vector<int> vec;
	vec.resize(size);
	for (int i = 0; i < size; i++) {
		int a = rand() % 1000 + 1;
		vec.at(i) = a;
	}
	return vec;
}