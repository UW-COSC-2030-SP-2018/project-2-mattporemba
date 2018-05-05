// Class to generate random vectors for testing
// Matt Poremba
// 5.3.18

#ifndef _TESTVECTOR_H_
#define _TESTVECTOR_H_

#include <vector>
using namespace std;

class TestVector {
public:
	TestVector(int size) {
		vec.resize(size);
		for (int i = 0; i < size; i++) {
			int a = rand() % 1000 + 1;
			vec.push_back(a);
		}
	}
private:
	vector<int> vec;
};

#endif _TESTVECTOR_H_

