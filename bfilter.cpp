#include <vector>
#include <iostream>
#include <cmath>
#include "bfilter.h"

using namespace std;

// (a)

class SillyHashFun : public HashFun {
    unsigned int operator()(const std::string& key) {
        return 0;
    }
};
/*
class GoodHashFun_0 : public HashFun {
    unsigned int operator()(const std::string& key) {
		unsigned int sum = 0;
		for (int i = 0; key[i] != '\0'; i++) //sum of ASCII values
			sum += int(key[i]);
		return sum;
    }
};*/

class HashFun_1 : public HashFun {
	unsigned int operator()(const std::string& key) {
		unsigned int hash_out = 0;
		for(int i = 0; key[i] != '\0'; i++) //polynomial hash
			hash_out += key[i] * pow(31, i);
		return hash_out;
    }
};

void BloomFilter::add_hash_funs() {
	//adding all hash functions
    //GoodHashFun_0 *h1 = new GoodHashFun_0();
	HashFun_1 *h2 = new HashFun_1();
    //this->hash_funs.push_back(h1);
	this->hash_funs.push_back(h2);
}

void BloomFilter::insert(const std::string& key) {
	//for loop to loop n hash function times
	for(int i = 0; i < hash_funs.size(); i++)  
		(this->filter)[call_hash(i, key) % 330] = 1;	
}

bool BloomFilter::member(const std::string& key) {
	unsigned int count = 0; //count all 1's in bitset
	for(int i = 0; i < hash_funs.size(); i++) {
		if((this->filter)[this->call_hash(i, key) % 330] == 1)
			count++;
	}
	if(count == hash_funs.size()) return true; //possible member if all hashes are in bitset
	return false;
}
