/* This file presents the interface for the String class,
     a class that stores character strings using run-time
     allocated arrays, while providing convenient operations
     to manipulate them.

   Written by: Joel C. Adams, Spring, 1993 at Calvin College.
------------------------------------------------------------*/

#ifndef STRINGS
#define STRINGS

#include <iostream>
#include <string.h>

using namespace std;

class Strings
{
  char                                            // container for starting
    *String_;                                     //   address of the array
  int                                             // the number of non-NUL
    Length_;                                      //   chars in the array

public:
  // *** Constructors, Destructor, and Converters.
  /*--- Constructor to build a Strings object from a char-string constant.

     Pre:     A Strings object has been declared,
                to be initialized with a character string constant.
     Recieve: Str, the char-string constant.
     Post:    The Strings object has been constructed/initialized
                appropriately to store the char-string constant.
  -----------------------------------------------------------------------*/
  Strings(const char Str[] = 0);


  /*--- Constructor to make a distinct copy of a Strings object.

     Pre:     A copy of a Strings object is needed by the compiler.
     Receive: Str, the String to be copied.
     Post:    This Strings object has been constructed/initialized
                as a copy of the original Strings object.
  -----------------------------------------------------------------------*/
  Strings(const Strings& Str);


  /*--- Constructor to build a Strings object of a particular size.

     Pre:     A Strings object has been declared,
                with an initialization character and
                with a given length.
     Receive: Ch, the initialization character, and
              Size, the length desired.
     Post:    This Strings object has been constructed/initialized
                with its Length_ member set to Size, and
                its String_ member pointing to an array of Size chars,
                each element containing the value Ch.
  -----------------------------------------------------------------------*/
  Strings(char Ch, unsigned Size = 1);


  /*--- Constructor to convert an int to a Strings object.

     Pre:     A Strings object has been declared
                with an int as an argument.
     Receive: IntVal, an int value.
     Post:    The object has been constructed and initialized
                as the Strings object equivalent to IntVal.
  -----------------------------------------------------------------------*/
  Strings(int IntVal);


  /*--- Constructor to convert an double to a Strings object.

     Pre:     A Strings object has been declared
                with a double as an argument.
     Receive: DoubleVal, an double value.
     Post:    The object has been constructed and initialized
                as the Strings object equivalent to DoubleVal.
  -----------------------------------------------------------------------*/
  Strings(double DoubleVal);


  /*--- Destructor to deallocate the memory of a Strings object.

     Pre:  A Strings object's lifetime is over.
     Post: The dynamic memory of that object has been reclaimed.
  -----------------------------------------------------------------------*/
  ~Strings(void);
                                                  // string conversions

  /*--- This function converts a String of digits to a double value.

     Pre:    This Strings object contains a sequence of digits.
     Return: The double value equivalent to those digits;
               0.0 if the conversion cannot be performed.
  -----------------------------------------------------------------------*/
  double Double(void);


  /*--- This function converts a String of digits to a long value.

     Pre:    This Strings object contains a sequence of digits.
     Return: The long value equivalent to those digits;
               0 if the conversion cannot be performed.
  -----------------------------------------------------------------------*/
  long Long(void);


  /*--- This function converts a String of digits to an unsigned long value.

     Pre:    This Strings object contains a sequence of digits.
     Return: The unsigned long value equivalent to those digits;
               0 if the conversion cannot be performed.
  -----------------------------------------------------------------------*/
  unsigned long Unsigned(void);


  /*--- This function converts a Strings object to the equivalent char-
         string whenever such a conversion is needed.

     Return: The char-string component of this Strings object.
  -----------------------------------------------------------------------*/
  operator const char*() const { return String_; }


  // *** Operations
  /*--- Length returns the number of characters in a Strings object.

     Return: The number of characters in this object.
  -----------------------------------------------------------------------*/
  int Length(void) const { return Length_; }


  /*--- Subscript: Retrieve the character with a given index.

     Receive: i, an index into this Strings object.
     Return:  The (reference of the) char at index i.
  -----------------------------------------------------------------------*/
  char& operator[] (unsigned i);
  char operator[] (unsigned i) const;


  /*--- Assignment to a Strings object.

     Receive: Str, a (reference to a) Strings object.
     Return:  This Strings object as a copy of Str.
  -----------------------------------------------------------------------*/
  Strings& operator= (const Strings& Str);


  /*--- Delete a portion of a Strings object.

     Receive: First, Last, two indices of this Strings object.
     Return:  This Strings object without the characters from First..Last
              True, if and only if the operation is successful.
  -----------------------------------------------------------------------*/
  int Delete(unsigned First, unsigned Last);


  /*--- Insert one Strings object into another Strings object.

     Receive: Str, a Strings object.
              Pos, an index within this Strings object.
     Return:  This Strings object with the characters of Str inserted
               starting at index Pos.
              True, if and only if the operation is successful.
  -----------------------------------------------------------------------*/
  int Insert(const Strings& Str, unsigned Pos);


  /*--- Replace a part of a Strings object with another Strings object.

     Receive: First, Last, two indices of this Strings object;
              Str, a Strings object.
     Return:  This Strings object with its characters of First through
               Last replaced with those of Str.
              True, if and only if the operation is successful.
  -----------------------------------------------------------------------*/
  int Replace(unsigned First, unsigned Last, const Strings& Str);


  /*--- Find the position of a substring within a Strings object.

     Receive: Str, a Strings object.
     Return:  The index of the first occurrence of Str within this Strings
               object (-1 if it is not present).
  -----------------------------------------------------------------------*/
  int Position(const Strings& Str) const;


  /*--- Concatenate two Strings objects.

     Receive: S1 and S2, two Strings objects.
     Return:  The Strings object consisting of S1 and S2.
  -----------------------------------------------------------------------*/
  friend Strings operator& (const Strings& S1, const Strings& S2);


  /*--- Retrieve a substring of a Strings object.

     Receive: First, Last, two indices of this Strings object.
     Return:  The substring of this Strings object that begins at
               index First and ends at index Last.
  -----------------------------------------------------------------------*/
  Strings operator() (unsigned First, unsigned Last);


  //--- Relational operators for Strings objects
  friend int operator== (const Strings& S1, const Strings& S2);
  friend int operator!= (const Strings& S1, const Strings& S2);
  friend int operator< (const Strings& S1, const Strings& S2);
  friend int operator> (const Strings& S1, const Strings& S2);
  friend int operator<= (const Strings& S1, const Strings& S2);
  friend int operator>= (const Strings& S1, const Strings& S2);

  //--- Relational operators for a String and a char-string
  friend int operator== (const Strings& S1, const char * S2);
  friend int operator!= (const Strings& S1, const char * S2);
  friend int operator< (const Strings& S1, const char * S2);
  friend int operator> (const Strings& S1, const char * S2);
  friend int operator<= (const Strings& S1, const char * S2);
  friend int operator>= (const Strings& S1, const char * S2);

  //--- Relational operators for a char-string and a String
  friend int operator== (const char * S1, const Strings& S2);
  friend int operator!= (const char * S1, const Strings& S2);
  friend int operator< (const char * S1, const Strings& S2);
  friend int operator> (const char * S1, const Strings& S2);
  friend int operator<= (const char * S1, const Strings& S2);
  friend int operator>= (const char * S1, const Strings& S2);


  // *** I/O
  friend ostream& operator<< (ostream& OutStream, const Strings& S);
  friend istream& operator>> (istream& InStream, Strings& S);

  // Bound on the number of chars that can be read ...
  enum {MaxLength = 1024};

  /*--- Operation to get a line of input from the keyboard or a file.

     Receive: InStream, the stream (i or f) being read from;
              MaxChars, a bound on the number of chars to be read
                           (default Strings::MaxLength);
              UntilChar, a char that halts the operation when it is read
                           (default newline).
     Return:  This Strings object, filled with either
               the next MaxChars characters from InStream, or
               all unread characters up to UntilChar in InStream,
               whichever is fewer.
  -----------------------------------------------------------------------*/
  istream& GetLine(istream& InStream,
                   unsigned MaxChars = Strings::MaxLength,
                   char UntilChar = '\n');
};

#endif
