// Matt Poremba
// hash.h

#ifndef _HASH_H_
#define _HASH_H_

#include <list>
#include <iostream>
using namespace std;
// Matt Poremba
// COSC 2030
// 5 May 2018
// hash.h

// Class to create a hash
// Code from: https://www.geeksforgeeks.org/c-program-hashing-chaining/
// Converting integers to integer hash
// This was pretty straight forward, I didn't adjust the code at all (here or .cpp)

class Hash
{
	int BUCKET;
	list<int> *table;
public:
	// Constructor
	Hash(int V);
	// Insert key into hash table
	void insertItem(int x);
	// Delete key from hash table
	void deleteItem(int key);
	// hash function to map values to key
	int hashFunction(int x) {
		return (x % BUCKET);
	}

	void displayHash();
};

#endif _HASH_H_

