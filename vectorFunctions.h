#ifndef _VECTORFUNCTIONS_H_
#define _VECTORFUNCTIONS_H_

#include <vector>
#include <iostream>
using namespace std;

// Used for debugging, prints a vector. Not suitable for large vectors.
void print(vector<int> v);

// qSort() takes a vector, left index, right index, and number to be found.
// Finds a pivot point in the middle, swaps integers around if they are not in order,
// recursively calls to higher/lower partition.
// Code found at: https://www.geeksforgeeks.org/quick-sort/
// Modified to handle empty vectors
void qSort(vector<int> &v, int left, int right);

// biSearch() is a binary sort that takes a vector, left index, right index, and number to be found.
// Splits sorted vector in half, searches for number in appriopriate half,
// returns the index where the number is first found.
// Code found at: https://www.geeksforgeeks.org/binary-search/
// Modified to handle empty vectors
int biSearch(vector<int> &v, int left, int right, int x);

// mSort() splits vector in half until all vectors are of size 1,
// then adds them back together, sorting as it goes.
// Code found at: https://codereview.stackexchange.com/questions/167680/merge-sort-implementation-with-vectors
void merge(vector<int>&left, vector<int>& right, vector<int>& bars);
void mSort(vector<int> & bar);

#endif _VECTORFUNCTIONS_H_