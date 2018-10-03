// This is the primer class

#include <iostream>	// contains ios
#include <fstream>		// contains ifstream
#include <stdlib.h>		// contains exit()

#include "strings.h"		// contains class Strings
#include "primer.h"		// contains class primer

int primer::primer_count = 0;

primer::primer(void)
{
	++primer_count;
}

primer::primer(Strings name_in)
{
	++primer_count;
	name = name_in;
}

primer::primer(Strings name_in, Strings file_name, int val)
{
	name = name_in;
}

primer::primer(Strings name_in, Strings sequence_in)
{
	++primer_count;
	name = name_in;
	sequence = sequence_in;
}

primer::~primer(void)
{
	--primer_count;
}

int primer::get_count(void)
{
	return (primer::primer_count);
}

Strings primer::get_name(void)
{
	return name;
}

Strings primer::get_sequence(void)
{
	return sequence;
}
