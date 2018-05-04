// Matt Poremba
// COSC 2030
// 23 April 2018
// Project 2

#include "TestVector.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Creates a vector of a specified size filled with random numbers.
vector<int> testVector(int size);

// Used for debugging, prints a vector. Not suitable for large vectors.
void print(vector<int> v);

// qSort() takes a vector, left index, right index, and number to be found.
// Finds a pivot point in the middle, swaps integers around if they are not in order,
// recursively calls to higher/lower partition.
// Code found at: https://www.geeksforgeeks.org/quick-sort/
void qSort(vector<int> &v, int left, int right);

// biSearch() is a binary sort that takes a vector, left index, right index, and number to be found.
// Splits sorted vector in half, searches for number in appriopriate half,
// returns the index where the number is first found.
// Code found at: https://www.geeksforgeeks.org/binary-search/
int biSearch(vector<int> &v, int left, int right, int x);

// 
// Code found at: https://www.geeksforgeeks.org/merge-sort/
void mSort(vector<int> &v, int left, int right);
void merge(vector<int> &v, int left, int mid, int right);

int main()
{
	// Create an array to hold test vectors,
	// initialize to hardcoded size and number of vectors
	const int numOfVectors = 1000;
	const int size = 100;
	vector<int> testVectors[numOfVectors];
	vector<int> testVectorsSTL[numOfVectors];
	for (int i = 0; i < numOfVectors; i++) {
		vector<int> temp = testVector(size);
		testVectors[i] = temp;
		testVectorsSTL[i] = temp;
	}

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
		vector<int> temp = testVector(size);
		testVectors[i] = temp;
		testVectorsSTL[i] = temp;
	}

	//Testing mSort()
	cout << "\n\nTESTING mSort():" << endl;

	return 0;
}

vector<int> testVector(int size)
{
	vector<int> vec;
	vec.resize(size);
	for (int i = 0; i < size; i++) {
		int a = rand() % 1000 + 1;
		vec.at(i) = a;
	}
	return vec;
}

void qSort(vector<int>& v, int left, int right)
{
	int i(left), j(right);
	int pivot = v[(left + right) / 2];
	int temp;
	// Partition
	while (i <= j) {
		while (v[i] < pivot) {
			i++;
		}
		while (v[j] > pivot) {
			j--;
		}
		// Swap
		if (i <= j) {
			temp = v[i];
			v[i] = v[j];
			v[j] = temp;
			i++;
			j--;
		}
	}
	// Recursion
	if (left < j) {
		qSort(v, left, j);
	}
	if (i < right) {
		qSort(v, i, right);
	}
}

int biSearch(vector<int>& v, int left, int right, int x)
{
	if (left <= right) {
		int mid = (left + right) / 2;	// dropped -1
		if (v[mid] == x) {
			return mid;
		}
		if (v[mid] > x) {
			return biSearch(v, left, mid - 1, x);
		}
		return biSearch(v, mid + 1, right, x);
	}
	// Return negative index if element not in array
	return -1;
}

void mSort(vector<int>& v, int left, int right)
{
	if (left < right) {
		// Finds midpoint
		int mid = left + (right - 1) / 2;
		// Sort left and right halves
		mSort(v, left, mid);
		mSort(v, mid + 1, right);
		// Bring arrays back together, sorting as we go
		merge(v, left, mid, right);

	}
}

void merge(vector<int>& v, int left, int mid, int right)
{
	int i, j, k;
	int n1 = mid - left + 1;
	int n2 = right - mid;

	// Temp vectors
	vector<int> Left(n1), Right(n2);			//DELETE: This may need to be resize?


}

void print(vector<int> v)
{
	for (int i = 0; i < v.size() - 1; i++) {
		cout << v.at(i) << ", ";
	}
	cout << v.back() << endl;
}