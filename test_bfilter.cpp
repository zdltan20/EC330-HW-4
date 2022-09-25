#include <iostream>
#include <vector>
#include <fstream>
#include "bfilter.h"

using namespace std;

int main() {
    cout << endl;
    BloomFilter bf = BloomFilter();
    /*bf.insert("Hello, World!");
    bf.insert("Lorem ipsum");

    std::cout << (bf.member("foo bar") ?
            "'foo bar' is in our bloom filter" :
            "'foo bar' is not in our bloom filter")
        << std::endl;
	*/
	
	/*
	ifstream myfile ("phishing-links-ACTIVE.txt");
	if (myfile.is_open()) {
		string line;
		while(myfile) {
			getline(myfile, line);
			bf.insert(line);
		}
		myfile.close();
	}
	*/
	
	bf.insert("i");
	bf.insert("1");
	bf.insert("IGNORE");
	bf.insert("7");
	
	cout << endl;
	cout << "populate success" << endl;
	
	//cout << "Member: " << bf.member("http://153284594738391.statictab.com/2506080?signed_request=vLSGIn9-mAPLo6LyP7j3KlFSRK21rVpIY43KPlBTDWI.eyJhbGdvcml0aG0iOiJITUFDLVNIQTI1NiIsImlzc3VlZF9hdCI6MTQxNjU0NDIzNywicGFnZSI6eyJpZCI6IjQ2MDk4ODc5NzI3ODA2NyIsImFkbWluIjpmYWxzZSwibGlrZWQiOnRydWV9LCJ1c") << endl;
	
	cout << "Member: " << bf.member("7") << endl;
	
    return 0;
}
