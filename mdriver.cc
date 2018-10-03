// mdriver.cc : driver file for the message class
//
// $Id: mdriver.cc,v 1.5 2002/03/11 19:29:45 barce Exp $
// 


#include <iostream> 	// contains ios
#include <fstream>		// contains ifstream
#include <stdlib.h>		// contains exit()

#include "strings.h"		// contains class Strings
#include "message.h"		// contains class message


int main(void)
{

	int i_exit = 0;	// if 1, program exits

	/* Change the message below for encryption and decryption. */
	Strings Message = "If I only knew then what I know now.";

	primer *pBarce1, *pBarce2;

	pBarce1 = new primer("START", "AAAAAAAAA");
	// pBarce1 = new primer("START", "123456789");
	// pBarce2 = new primer("END", "123456789");
	pBarce2 = new primer("END", "AAAAAAAAC");

	/* 

	   Problem: What if the primer matches a part of the
	   encrypted message? 

	   Solution: "Recalibrate" the primer.

	*/

	cout << "get_name: " << pBarce1->get_name() << '\n';
	cout << "get_sequence: " << pBarce1->get_sequence() << '\n';

	cout << "decrementing pointer for primer...\n";

	cout << "get_name: " << pBarce2->get_name() << '\n';
	cout << "get_sequence: " << pBarce2->get_sequence() << '\n';

	hash *fileHash;
	fileHash = new hash("table1", "4dna");

	message *mSecret;
	mSecret = new message(pBarce1, pBarce2, fileHash, Message, 1);

	cout << "encoding... \n";
	Strings Encoded = mSecret->encode();
	cout << Encoded << "\n";

	message *mNotSecret;
	mNotSecret = new message(pBarce1, pBarce2, fileHash, Encoded, 0);

	cout << "\ndecoding\n";
	Strings Decoded = mNotSecret->decode();
	cout << Decoded << "\n";

	// delete fileHash;
	// delete []pBarce;

	return 0;
}

