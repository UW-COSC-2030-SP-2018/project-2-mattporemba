// Matt Poremba
// COSC 2030
// 5 May 2018
// hash.cpp

#include "hash.h"

// Code from: https://www.geeksforgeeks.org/c-program-hashing-chaining/

Hash::Hash(int b)
{
	this->BUCKET = b;
	table = new list<int>[BUCKET];
}

void Hash::insertItem(int key)
{
	int index = hashFunction(key);
	table[index].push_back(key);
}

void Hash::deleteItem(int key)
{
	// get the hash index of key
	int index = hashFunction(key);

	// find the key in (inex)th list
	list <int> ::iterator i;
	for (i = table[index].begin();
		i != table[index].end(); i++) {
		if (*i == key)
			break;
	}

	// if key is found in hash table, remove it
	if (i != table[index].end())
		table[index].erase(i);
}

// function to display hash table
void Hash::displayHash() {
	for (int i = 0; i < BUCKET; i++) {
		cout << i;
		for (auto x : table[i])
			cout << " --> " << x;
		cout << endl;
	}
}