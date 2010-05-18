// primer.h
// --------
// This is a hash class
#include <iostream.h> 	// contains ios
#include <fstream.h>		// contains ifstream
#include <stdlib.h>		// contains exit()

#include "strings.h"		// contains class Strings


class primer {
private:
	Strings name;
	Strings sequence;
	static int primer_count;	// Number of primers in use
public:

	// The constructors
	primer (void);
	primer (Strings name_in);
	primer (Strings name_in, Strings file_name, int val);
	primer (Strings name_in, Strings sequence_in);

	~primer (void);

	// The methods
	static int get_count(void);	// returns the number of primers
	Strings get_name(void);				// returns the primer name
	Strings get_sequence(void);		// returns the sequence for the primer
};

