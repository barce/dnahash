// genperms.cc
//
// $Id: genperms.cc,v 1.3 2001/11/21 06:33:53 barce Exp $
// --------------------------------


#include <iostream.h>
#include <unistd.h>
#include <stdlib.h>
#include "strings.h"

static char *argv0=NULL;

Strings perm(Strings passed, Strings *Sequence, int Seqlen, int Permlen);

void usage(void);
void missing_arg(void);
void bad_arg(char*);
void help(void);
void version(void);

int main(int argc, char** argv)
{

	int argn = 1; // used to parse options
	unsigned p = 0; // number of chars per generated string
	int tmp;

	argv0 = argv[0];

	if (argc == 1)
	{
		usage();
		exit(-1);
	}

	if (argv[argn][0] == '-')
	{
		while (argn < argc)
		{
			if (strcmp(argv[argn], "-p") == 0)
			{ 
				++argn;
				if (argn >= argc)
				{
					missing_arg();
					exit(-1);
				}
				tmp = atoi(argv[argn]);
				if (tmp)
					p += tmp;
				else
					bad_arg(argv[argn]);
			}

			if (strcmp(argv[argn], "-v") == 0)
			{
				version();
			}
			++argn;
		} // end while
	} // endif for opts

	// int len = 4;	// elements in array Sequence
	int len = 60;	// elements in array Sequence
	int strlen = p;	// length of each Permutation String
	Strings *Sequence = new Strings[len];

/*
	Sequence[0] = "A";
	Sequence[1] = "C";
	Sequence[2] = "G";
	Sequence[3] = "T";
*/

Sequence[0] = "a";
Sequence[1] = "b";
Sequence[2] = "c";
Sequence[3] = "d";
Sequence[4] = "e";
Sequence[5] = "f";
Sequence[6] = "g";
Sequence[7] = "h";
Sequence[8] = "i";
Sequence[9] = "j";
Sequence[10] = "k";
Sequence[11] = "l";
Sequence[12] = "m";
Sequence[13] = "n";
Sequence[14] = "o";
Sequence[15] = "p";
Sequence[16] = "q";
Sequence[17] = "r";
Sequence[18] = "s";
Sequence[19] = "t";
Sequence[20] = "u";
Sequence[21] = "v";
Sequence[22] = "w";
Sequence[23] = "x";
Sequence[24] = "y";
Sequence[25] = "z";
Sequence[26] = "A";
Sequence[27] = "B";
Sequence[28] = "C";
Sequence[29] = "D";
Sequence[30] = "E";
Sequence[31] = "F";
Sequence[32] = "G";
Sequence[33] = "H";
Sequence[34] = "I";
Sequence[35] = "J";
Sequence[36] = "K";
Sequence[37] = "L";
Sequence[38] = "M";
Sequence[39] = "N";
Sequence[40] = "O";
Sequence[41] = "P";
Sequence[42] = "Q";
Sequence[43] = "R";
Sequence[44] = "S";
Sequence[45] = "T";
Sequence[46] = "U";
Sequence[47] = "V";
Sequence[48] = "W";
Sequence[49] = "X";
Sequence[50] = "Y";
Sequence[51] = "Z";
Sequence[52] = "0";
Sequence[53] = "1";
Sequence[54] = "2";
Sequence[55] = "3";
Sequence[56] = "4";
Sequence[57] = "5";
Sequence[58] = "6";
Sequence[59] = "7";
Sequence[60] = "8";
Sequence[61] = "9";
	
	perm("", Sequence, len, strlen);

	delete []Sequence;
	Sequence = NULL;

	return 0;
}

Strings perm(Strings passed, Strings *Sequence, int Seqlen, int Permlen)
{

	int i = 0;
	int counter = 0;

	for (i = 0; i < Seqlen; i++)
	{
		if ( passed.Length() == Permlen )
		{
			if (counter == 0) { cout << "\n"; }
			counter++;
		}
		else
		{
			if (passed.Length() == (Permlen - 1)) 
				cout << passed << Sequence[i];

			perm(passed & Sequence[i], Sequence, Seqlen, Permlen);
		}
	}
	return "0";
}

void usage()
{
	cout << "usage: genperms -p int \n";
	cout << "\t" << "where int is the length of the string \n";
	cout << "\t" << "for storing permutations \n";
}

void missing_arg()
{
	cout << "argument missing \n\n";
}

void bad_arg(char* arg)
{
	if (strcmp(arg, "-h") == 0  || strcmp(arg, "--help") == 0)
	{
		usage();
		help();
		exit(-1);
	}
	else if (strcmp(arg, "-v") == 0 || strcmp(arg, "--version") == 0)
	{
		version();
		exit(-1);
	}

	cout << argv0 << ": invalid option \'" << arg << "\'\n";
	cout << "Try \'" << argv0 << " --help\' for more information.\n";
	cout << "\n";
	exit(-1);
}

void help()
{
	cout << "help text \n\n";
}

void version()
{
	cout << "Genperms Version 0.1 by barce@cyphgen.com (c) 2001 \n\n";
}
