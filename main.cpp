// Matt Poremba
// COSC 2030
// 23 April 2018
// Project 2

#include <iostream>
#include <vector>
#include <algorithm>
#include "vectorFunctions.h"
#include "bloom.h"
#include "hash.h"

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
	// Corner cases of empty and only single element
	qSort(corner1, 0, 0);
	cout << "Sorted empty vector: ";
	print(corner1);
	qSort(corner2, 0, size - 1);
	cout << "Sorted single element vector: ";
	print(corner2);

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
	// Test searching empty, and searching something that doesn't exists
	int indexFound = biSearch(corner1, 0, 0, 100);
	cout << "Searching for 100 in empty vector, index returned: " << indexFound << endl;
	indexFound = biSearch(corner2, 0, corner2.size() - 1, 100);
	cout << "Searching for element that does NOT exist in a vector, index returned: " << indexFound << endl;
	indexFound = biSearch(corner2, 0, corner2.size() - 1, 1);
	cout << "Searching for element that DOES exists in a vector of size 1, index returned: " << indexFound << endl;

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
	// Testing corner cases, sorted an empty vector and size 1 vector
	mSort(corner1);
	cout << "Merge sort of empty vector: ";
	print(corner1);
	mSort(corner2);
	cout << "Merge sort of vector size 1: ";
	print(corner2);

	// Testing hash class
	// Array with keys
	cout << "\n\nTESTING hash function:" << endl << "Create a hash with 10 buckets, init:" << endl;
	int a[] = { 20, 131, 23, 56, 2, 13, 47, 4, 32 };
	// Size of array
	int n = sizeof(a) / sizeof(a[0]);
	Hash h(10);
	for (int i = 0; i < n; i++) {
		h.insertItem(a[i]);
	}
	h.displayHash();
	cout << "\nDelete a hash that has been chained(23):" << endl;
	h.deleteItem(23);
	h.displayHash();

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