#include "bloom.h"

BloomFilter::BloomFilter(int size, int numHashes) : m_bits(size), m_numHashes(numHashes) {}

