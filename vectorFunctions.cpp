#include "vectorFunctions.h"

// Original code from: https://www.geeksforgeeks.org/quick-sort/
void qSort(vector<int>& v, int left, int right)
{
	if (v.size() <= 1) {
		return;
	}
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

// Original code: https://www.geeksforgeeks.org/binary-search/
int biSearch(vector<int>& v, int left, int right, int x)
{
	if (v.size() == 0) {
		return -1;
	}
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

// Original code from: https://codereview.stackexchange.com/questions/167680/merge-sort-implementation-with-vectors
void mSort(vector<int> & bar) {
	if (bar.size() <= 1) return;

	int mid = bar.size() / 2;
	vector<int> left;
	vector<int> right;

	for (size_t j = 0; j < mid; j++)
		left.push_back(bar[j]);
	for (size_t j = 0; j < (bar.size()) - mid; j++)
		right.push_back(bar[mid + j]);

	mSort(left);
	mSort(right);
	merge(left, right, bar);
}

// Original code from: https://codereview.stackexchange.com/questions/167680/merge-sort-implementation-with-vectors
void merge(vector<int>&left, vector<int>& right, vector<int>& bars)
{
	int nL = left.size();
	int nR = right.size();
	int i = 0, j = 0, k = 0;

	while (j < nL && k < nR)
	{
		if (left[j] < right[k]) {
			bars[i] = left[j];
			j++;
		}
		else {
			bars[i] = right[k];
			k++;
		}
		i++;
	}
	while (j < nL) {
		bars[i] = left[j];
		j++; i++;
	}
	while (k < nR) {
		bars[i] = right[k];
		k++; i++;
	}
}

void print(vector<int> v)
{
	if (v.size() == 0) {
		cout << "{}" << endl;
		return;
	}
	cout << "{";
	for (int i = 0; i < v.size() - 1; i++) {
		cout << v.at(i) << ", ";
	}
	cout << v.back() << "}" << endl;
}