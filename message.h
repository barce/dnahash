// message.h
// ---------
// A message is a combination of the primer and dnahash class

#include <iostream.h>   // contains ios
#include <fstream.h>            // contains ifstream
#include <stdlib.h>             // contains exit()

#include "strings.h"            // contains class Strings
#include "primer.h"
#include "hash.h"

class message {
private:
	primer *pStart;
	primer *pEnd;
	hash *hTable;
	int mode;			// if 1, then encode, else decode
	Strings input;		// either the encoded or decoded message
	Strings result;	// either the decoded or encoded message
public:

// ---- Constructors
	message();
	message(int num_primers);

	// inSet is a pointer to an array of primers
	// inHash is a pointer to a dnahash
	// inMesg is the message to be either decoded or encoded
	// i_encode, if 1 means encode message, if 0 means decode message
	message(primer *p1, primer *p2, hash *inHash, Strings inMesg, int i_encode);

// ---- Destructor
	~message();

	Strings encode ();	// encodes input and returns string
	Strings decode ();	// decodes input and returns string
	Strings readFile (Strings filename);
	int getmode();			// returns mode
};
