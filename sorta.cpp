#include <string>
#include <iostream>
#include "sorta.h"

using namespace std;

void bubbleSort(int count[][2], int size) { //bubble sort for 2d count array
	
	bool swapped;
	
	for (int i = 0; i < size - 1; i++) {
		swapped = false;
		for (int j = 0; j < size - i - 1; j++) {
			if(count[j][1] > count[j+1][1]) { //swap both frequency and ascii equivalent
				int temp_val = count[j][1];
				count[j][1] = count[j+1][1];
				count[j+1][1] = temp_val;
				
				int temp_char = count[j][0];
				count[j][0] = count[j+1][0];
				count[j+1][0] = temp_char;
				
				swapped = true;
			}
		}
		if(!swapped) break;
	}
}

std::string sortByFreq(std::string s) {
	int size = s.length();
	int s_int[size];
	int count[26][2]; //because 26 letters in the alphabet
	std::string s_out = "";
	
	for (int i = 0; i < size; i++) //store ASCII equivalent in temp array
		s_int[i] = int(s[i]);
	
	for (int i = 0; i < 26; i++)
		count[i][1] = 0;
	
	for (int i = 0; i < 26; i++) 
		count[i][0] = i + 97;
	
	for (int i = 0; i < size; i++) //count and increment
		count[s_int[i] - 97][1]++;
	
	bubbleSort(count, 26); //stable sort

	for (int i = 0; i < 26; i++) { //sorted by frequency then alphabetical and concatenate
		for (int j = 0; j < count[i][1]; j++) 
			s_out = s_out + char(count[i][0]);
	}
	
	//return s_out;
	return {s_out};
}