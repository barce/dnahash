// A message is a combination of the primer and dnahash class

#include <iostream>   // contains ios
#include <fstream>            // contains ifstream
#include <stdlib.h>             // contains exit()

#include "strings.h"            // contains class Strings
#include "message.h"

using namespace std;

message::message() 
{


}

message::message(int num_primers)
{
	int i_primer = num_primers;
	pStart = new primer[i_primer];	// dynamically allocate an array

	Strings name;
	Strings sequence;

	cout << "i_primer: " << i_primer << "\n";
	for (int i = 0; i < i_primer; i++)
	{
		
		cout << "Name: ";
		cin >> name;
		cout << "Sequence: ";
		cin >> sequence;
		cout << "i = " << i << "\n";

		pStart[i] = primer(name, sequence);
	}
}

message::message(primer *p1, primer *p2, hash *inHash, Strings inMesg, int i_encode)
{
	pStart = p1;
	pEnd = p2;
	hTable = inHash;
	mode = i_encode;
	input = inMesg;
}

// Destructor
message::~message()
{
	delete pStart;
	delete pEnd;
	delete hTable;
}

// ---- Methods

Strings message::encode() 
{
	Strings seq;
	Strings code;
	int mesg_length = input.Length();

	// add 1st primer:
	code = pStart->get_sequence();

	// encode message
	for (int i = 0; i < mesg_length; i++) {
		seq = hTable->getSeq(input(i,i));
		code = code & seq;
	}

	// add 2nd primer:
	code = code & pEnd->get_sequence();

	result = code; // this sets result to code
	return code;
}

Strings message::decode ()
{

	Strings seq;
	Strings code;
	Strings s_primer;

	int i_start;
	int i_end;
	int seqL = hTable->getSeqLength();

	s_primer = pStart->get_sequence();
	i_start  = s_primer.Length();
	i_end    = input.Length() - (i_start * 2) + 5;

	for (int i = i_start; i <= i_end; i+=seqL)
	{
		seq = hTable->getChar(input(i,i+(seqL-1)));
		code = code & seq;
	}
	result = code;
	return code;
}

Strings message::readFile (Strings filename)
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

int message::getmode ()
{
	return mode;
}
