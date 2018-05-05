#ifndef _BLOOMFILTER_H_
#define _BLOOMFILTER_H_

#include <vector>
using namespace std;

// Code from: http://blog.michaelschmatz.com/2016/04/11/how-to-write-a-bloom-filter-cpp/

struct BloomFilter {
	BloomFilter(int size, int numHashes);
	void add(const int *data, std::size_t len);
	bool possiblyContains(const int *data, std::size_t len) const;

private:
	int m_numHashes;
	vector<bool> m_bits;
};

#endif _BLOOMFILTER_H_

