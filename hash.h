// hash.h
// ------
// This is a hash class


#include <iostream> 	// contains ios
#include <fstream>		// contains ifstream
#include <stdlib.h>		// contains exit()

#include "strings.h"		// contains class Strings

using namespace std;

const int HASH_SIZE = 200;

class hash {
private:
	Strings table[HASH_SIZE];
	Strings name;
	int count;
	int i_seq;	// the default length for every sequence
public:

//--------- Constructors -------------

	// The constructors
	hash (void);
	hash (Strings hash_name);

	// Contruct based on a hash name & file name;
	hash (Strings hash_name, Strings file_name);

//--------- Methods -------------


	// Add a key-value pair to the hash
	void add(Strings key, Strings value);

	// return the number of elements in the array, table
	int getcount();

	// return the sequence length 
	int getSeqLength();

	// this function returns the character for a given sequence
	Strings getChar(Strings seq);

	// this function returns the sequence for a given character
	Strings getSeq(Strings Char);

	// print out the hash
	void printhash();

	// print out the number of elements in table
	void printcount();
};

