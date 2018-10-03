// main.cc : driver file for the hash class
//
// $Id: driver.cc,v 1.5 2001/11/21 06:33:53 barce Exp $
// by: barce


#include <iostream> 	// contains ios
#include <fstream>		// contains ifstream
#include <stdlib.h>		// contains exit()

#include "strings.h"		// contains class Strings
#include "hash.h"			// contains class hash
#include "primer.h"		// contains class primer

using namespace std;

Strings encode (Strings mesg, hash theHash);
Strings decode (Strings mesg, hash theHash);
Strings readFile (Strings filename);

int main(void)
{

	int i_exit = 0;	// if 1, program exits

	Strings letter = "";
	Strings seq = "";
	Strings sub = "";
	Strings code = "";
	Strings decoded_msg = "";
	Strings tmp_input = "";
	Strings mesg = "";			// The message to be encoded.


	while (i_exit < 1) {
	
		// usage: hash filehash("table", "file_of_perms.txt");
		hash fileHash("table1", "4dna");
	
		// Read in a file for mesg
		mesg = "Once upon a time I had a stroke of bad luck.";
	
		code = encode(mesg, fileHash);
	
		cout << mesg << " is:\n";
		cout << code;
		cout << "\n";
		cout << "\n";
	
		cout << "Decoding the above message...\n";
		decoded_msg = decode(code, fileHash);
		cout << decoded_msg << "\n";
		cout << "\n";
	
		primer First("First", "GATTACA");
		cout << "Primer count: " << primer::get_count() << "\n";
		primer Second("Second", "ACATTAG");
		cout << "Primer count: " << primer::get_count() << "\n";
	
		Strings space = " ";
		Strings spaces = "  ";
	
		cout << "spaces: " << spaces.Length() << "\n";
		cout << "space: " << space.Length() << "\n";

		i_exit = 1;	// exit loop
	}
	return 0;
}

Strings encode (Strings mesg, hash theHash)
{
	Strings seq;
	Strings code;
	int mesg_length = mesg.Length();

	for (int i = 0; i < mesg_length; i++) {
		seq = theHash.getSeq(mesg(i,i));
		code = code & seq;
	}
	return code;

}

Strings decode (Strings mesg, hash theHash)
{

	Strings seq;
	Strings code;

	int seqL = theHash.getSeqLength();
	for (int i = 0; i < mesg.Length(); i+=seqL)
	{
		seq = theHash.getChar(mesg(i,i+(seqL-1)));
		code = code & seq;
	}
	return code;
}

Strings readFile (Strings filename)
{
	ifstream
		InStream;
	Strings tmp_input = "";
	Strings mesg = "";

	InStream.open(filename, ios::in);

	while (!InStream.eof()) {
		InStream >> tmp_input;
		tmp_input = tmp_input & " ";
		mesg = mesg & tmp_input;
	}

	InStream.close();
	return mesg;
}
