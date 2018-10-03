// This is a hash class
//
// date: 9 August 2000
// by: barce

#include <iostream> 	// contains ios
#include <fstream>		// contains ifstream
#include <stdlib.h>		// contains exit()

#include "strings.h"		// contains class Strings
#include "hash.h"			// contains hash class

using namespace std;

// The constructor
hash::hash (void) {
count = 0;
}

hash::hash (Strings hash_name) {
	count = 0;
	name = hash_name;
}

// Contruct based on a hash name & file name;
hash::hash (Strings hash_name, Strings file_name) {
	ifstream
		InStream;
	int num_inputs = 0;
	Strings tmp_input;

	name = hash_name;

	InStream.open(file_name, ios::in);

	while (!InStream.eof()) {
		num_inputs++;
		InStream >> tmp_input;
	}

	InStream.close();

	num_inputs--;
	count = num_inputs;

	InStream.open(file_name, ios::in|ios::binary);

	for (int i = 0; i < num_inputs; i++) {
		InStream >> table[i];
		if (i == 1) { i_seq = table[i].Length(); }
	}
	InStream.close();

}

void hash::add(Strings key, Strings value) {
	table[count] = key;
	++count;
	table[count] = value;
	if (count == 1) { i_seq = value.Length(); }
	++count;
}

int hash::getcount() {
	return count;
}

int hash::getSeqLength() {
	return i_seq;
}

// this function returns the character for a given sequence
Strings hash::getChar(Strings seq) {
	int i = 1;
	int i_sentinel = 0;
	Strings Char = "";

	// Search odd numbers & look for sequences
	while (i_sentinel == 0) {
		if (table[i] == seq) {
			i_sentinel = 1;
			Char = table[i-1];
		} else if (i >= count) {
			i_sentinel = 1;
			Char = "000 000";
		} else {
			i+=2;
		}
	}
	if (Char == "_") {
		Char = " ";
	}
	return Char;
}

// this function returns the sequence for a given character
Strings hash::getSeq(Strings Char) {
	int i = 0;
	int i_sentinel = 0;
	Strings Seq = "";

	// Search evens & look for Chars
	while (i_sentinel == 0) {
		if (" " == Char) {
			Char = "_";
		} else if (table[i] == Char) {
			i_sentinel = 1;
			Seq = table[i+1];
		} else if (i >= count) {
			i_sentinel = 1;
			Seq = "000 000";
		} else {
			i+=2;
		}
	}
	return Seq;
}	

void hash::printhash() {
	for (int i = 0; i < count; i++)
	{
		cout << table[i] << "\n";
	}
}

void hash::printcount() {
	cout << getcount() << "\n";
}


