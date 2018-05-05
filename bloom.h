// Matt Poremba
// COSC 2030
// 5 May 2018
// bloom.h

#ifndef _BLOOMFILTER_H_
#define _BLOOMFILTER_H_

#include <vector>
#include "hash.h"
using namespace std;

// Code from: http://blog.michaelschmatz.com/2016/04/11/how-to-write-a-bloom-filter-cpp/
// I have absolutely no idea what this blog is trying to explain,
// and other sources I've looked at are even more confusing.
// AKA, this is incomplete and doesn't work. Sorry.

struct BloomFilter {
	// Constructor
	BloomFilter(int size, int numHashes)
		: m_bits(size), m_numHashes(numHashes) {}

	void add(const int *data, std::size_t len);

	bool possiblyContains(const int *data, std::size_t len) const;

	int hash(const uint8_t *data, std::size_t len)
	{
		// Simple hash
		int hashValue = *data % 100;
		return hashValue;
	}


private:
	int m_numHashes;
	vector<bool> m_bits;
};

#endif _BLOOMFILTER_H_

