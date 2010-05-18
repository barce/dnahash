/* This file contains the definitions of the operations of class Strings.
    The declaration of class Strings can be found in Strings.h

   Written by: Joel C. Adams, Spring, 1993, at Calvin College.
------------------------------------------------------------------*/

#include "strings.h"                         // header for this file

#include <stdlib.h>                          // exit()
#include <assert.h>                          // assert()

const char                                   // error/warning messages
   FirstPastLast[] = "\n*** 1st index exceeds 2nd index in call to ",
   LastTooBig[] = "\nw - 2nd index exceeds string length in call to ";


/*--- Constructor to build a Strings object from a char-string constant.

   Pre:     A Strings object has been declared,
              to be initialized with a character string constant.
   Recieve: Str, the char-string constant.
   Post:    The Strings object has been constructed/initialized
              appropriately to store the char-string constant.
-----------------------------------------------------------------------*/

Strings::Strings(const char Str[])
{
  if (Str == 0)                            // if Str has default value
  {
     Length_ = 0;                          //   Length_ gets zero
     String_ = 0;                          //   String_ gets NULL
  }
  else                                     // else
  {
     Length_ = strlen(Str);                //   Length_ gets length of Str
     String_ = new char[Length_ + 1];      //   allocate array for String_
     assert(String_ != 0);                 //   verify
     strcpy(String_, Str);                 //   copy Str into the array
  }
}

/*--- Constructor to make a distinct copy of a Strings object.

   Pre:     A copy of a Strings object is needed.
   Receive: Str, the String to be copied.
   Post:    This Strings object has been constructed/initialized
              as a copy of the original Strings object.
----------------------------------------------------------------------*/

Strings::Strings(const Strings& Str)
{
  Length_ = Str.Length_;               // copy Length_ member of Str

  if (Str.String_ == 0)                // if Str is empty
    String_ = 0;                       //   make copy empty too
  else                                 // else
    {
      String_ = new char[Length_+1];   //   allocate new array
      assert(String_ != 0);            //   verify
      strcpy(String_, Str.String_);    //   copy Str into the array
    }
}

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

Strings::Strings(char Ch, unsigned Size)
{
  Length_ = Size;                 // set Length_
  String_ = new char[Size+1];     // allocate new array
  assert(String_ != 0);           // verify
  for (int i = 0; i <= Size; i++) // fill the array\'s elems
    String_[i] = Ch;              //   with Ch chars
  String_[Size] = '\0';           // tack on NUL terminator
}

/*--- Constructor to convert an int to a Strings object.

   Pre:     A Strings object has been declared
              with an int as an argument.
   Receive: IntVal, an int value.
   Post:    The object has been constructed and initialized
              as the Strings object equivalent to IntVal.
-----------------------------------------------------------------------*/

#include <stdio.h>                          // provides us with sprintf()

Strings::Strings(int IntVal)
{
  char
    A[80];                                  // char string to store value

  sprintf(A, "%i", IntVal);                 // convert value to a string
  Length_ = strlen(A);                      // Length_ gets length of A
  String_ = new char[Length_ + 1];          // allocate array for String_
  assert(String_ != 0);                     // verify
  strcpy(String_, A);                       // copy A into the array
}


/*--- Constructor to convert an double to a Strings object.

   Pre:     A Strings object has been declared
              with a double as an argument.
   Receive: DoubleVal, an double value.
   Post:    The object has been constructed and initialized
              as the Strings object equivalent to DoubleVal.
-----------------------------------------------------------------------*/

Strings::Strings(double DoubleVal)
{
  char
    A[80];                                  // char string to hold value

  sprintf(A, "%d", DoubleVal);              //  convert value to a string
  Length_ = strlen(A);                      //  Length_ gets length of A
  String_ = new char[Length_ + 1];          //  allocate array for String_
  assert(String_ != 0);                     //  verify
  strcpy(String_, A);                       //  copy A into the array
}

/*--- Destructor to deallocate the memory of a Strings object.

   Pre:  A Strings object's lifetime is over.
   Post: The dynamic memory of that object has been reclaimed.
-----------------------------------------------------------------------*/

Strings::~Strings(void)
{
  delete [] String_;            // deallocate array of this object
  String_ = 0;
  Length_ = 0;                  // set its Length_ to zero.
}

/*--- This function converts a String of digits to a double value.

   Pre:    This Strings object contains a sequence of digits.
   Return: The double value equivalent to those digits;
             0.0 if the conversion cannot be performed.
-----------------------------------------------------------------------*/

double Strings::Double(void)
{
  return strtod(String_, NULL);
}

/*--- This function converts a String of digits to a long value.

   Pre:    This Strings object contains a sequence of digits.
   Return: The long value equivalent to those digits;
             0 if the conversion cannot be performed.
-----------------------------------------------------------------------*/

long Strings::Long(void)
{
  return strtol(String_, NULL, 0);
}

/*--- This function converts a String of digits to an unsigned long value.

   Pre:    This Strings object contains a sequence of digits.
   Return: The unsigned long value equivalent to those digits;
             0 if the conversion cannot be performed.
-----------------------------------------------------------------------*/

unsigned long Strings::Unsigned(void)
{
  return strtoul(String_, NULL, 0);
}

/*--- Assignment to a Strings object.

   Receive: Str, a (reference to a) Strings object.
   Return:  This Strings object as a copy of Str.
-----------------------------------------------------------------------*/

Strings& Strings::operator= (const Strings& Str)
{
  if (String_ != Str.String_)                // if the two are different
    {
      Length_ = Str.Length_;                 //    copy Length_ member
      delete [] String_;                     //    deallocate the array

      if (Str.String_ == 0)                  //    if Str is empty
        String_ = 0;                         //      make this empty too
      else                                   //    else
        {
          String_ = new char[Str.Length_+1]; //      allocate a new array
          assert(String_ != 0);              //      verify
          strcpy(String_, Str.String_);      //      fill array using Str
        }
    }
  return *this;                              //  return this object
}

/*--- Subscript: Retrieve the character with a given index.

   Receive: i, an index into this Strings object.
   Return:  The (reference of the) char at index i.
-----------------------------------------------------------------------*/

char& Strings::operator[] (unsigned i)
{
  if (i < Length_)
    return String_[i];
  else
  {
     cerr << "\n*** Attempted access past end of String in [].\n";
     exit (-1);
     return String_[i];
  }
}

char Strings::operator[] (unsigned i) const
{
  if (i < Length_)
    return String_[i];
  else
  {
     cerr << "\n*** Attempted access past end of String in [].\n";
     exit (-1);
     return String_[i];
  }
}

/*--- Delete a portion of a Strings object.

   Receive: First, Last, two indices of this Strings object.
   Return:  This Strings object without the characters from First..Last
            True, if and only if the operation is successful.
-----------------------------------------------------------------------*/

int Strings::Delete(unsigned First, unsigned Last)
{
  if (Last >= Length_)                        // if Last past end of string
    {
      cerr << LastTooBig << "Delete.\n";      //   issue warning message
      Last = Length_ - 1;                     //   build empty part part
    }

  if (First > Last)                           // if Last not <= First
    {
      cerr << FirstPastLast << "Delete.\n";   //   issue error message
      return 0;                               //     and terminate
    }

  Strings                                     // return value's
    LeftPart,                                 //   left substring
    RightPart;                                //   and right substring

  if (First == 0)                             // if start at first char
    LeftPart = "";                            //    Left is empty
  else                                        // otherwise
    LeftPart = (*this)(0, First-1);           //    Left is before First

  if (Last == Length_ - 1)                    // if end is at last char
    RightPart = "";                           //    Right is empty
  else                                        // otherwise
    RightPart = (*this)(Last+1, Length_ - 1); //    Right is past Last

  (*this) = LeftPart & RightPart;             // concatenate the two substr

  return 1;                                   // indicate success
}

/*--- Insert one Strings object into another Strings object.

   Receive: Str, a Strings object.
            Pos, an index within this Strings object.
   Return:  This Strings object with the characters of Str inserted
              starting at index Pos.
            True, if and only if the operation is successful.
-----------------------------------------------------------------------*/

int Strings::Insert(const Strings& Str, unsigned Pos)
{
  const char
    PosTooBig[] = "\nInsert: insertion point past end of string !\n";

  if (Pos > Length_)                       // if Pos past end of string
    {
      cerr << PosTooBig;                   //    display warning msg
      Pos = Length_;                       //    set Pos to NULL char
    }

  Strings                                  // return value's
    LeftPart,                              //    left substring
    RightPart;                             //    and right substring

  if (Pos == 0)                            // if inserting at beginning
    LeftPart = "";                         //    Left is empty
  else                                     // otherwise
    LeftPart = (*this)(0, Pos-1);          //    Left is what's before Pos

  if (Pos == Length_)                      // if inserting at end
    RightPart = "";                        //    Right is empty
  else                                     // otherwise
    RightPart = (*this)(Pos, Length_-1);   //    Right is from Pos onwards

  (*this) = LeftPart & Str & RightPart;    // concatenate Left, Str, Right

  return 1;                                // return success
}

/*--- Replace a part of a Strings object with another Strings object.

   Receive: First, Last, two indices of this Strings object;
            Str, a Strings object.
   Return:  This Strings object with its characters of First through
              Last replaced with those of Str.
            True, if and only if the operation is successful.
-----------------------------------------------------------------------*/

int Strings::Replace(unsigned First, unsigned Last, const Strings& Str)
{
  if (Last >= Length_)                       // if Last past end of string
    {
      cerr << LastTooBig << "Replace.\n";    //    display warning msg
      Last = Length_ - 1;                    //    and set Last to last char
    }

  if (Last < First)                          // if First not <= Last
    {
      cerr << FirstPastLast << "Replace.\n"; //    display error msg
      return 0;                              //    and terminate
    }

  Delete(First, Last);                       // remove the substring to
                                             //   be replaced
  Insert(Str, First);                        // insert the replacement
                                             //   at position First
  return 1;                                  // indicate success
}

/*--- Find the position of a substring within a Strings object.

   Receive: Str, a Strings object.
   Return:  The index of the first occurrence of Str within *this
              (-1 if it is not present).
-----------------------------------------------------------------------*/

int Strings::Position(const Strings& Str) const
{
  for (int i = 0; i < Length_; i++)         // for each substring of *this:
    if (strncmp(String_ + i,                //   if the substring at offset i
                Str.String_,                //      and the string in Str
                Str.Length()                //       (not counting the NULL)
                ) == 0)                     //      are equal
      return i;                             //      then return the location

  return -1;                                // Str is not in *this
}

/*--- Concatenate two Strings objects.

   Receive: S1 and S2, two Strings objects.
   Return:  The Strings object consisting of S1 and S2.
-----------------------------------------------------------------------*/

Strings operator& (const Strings& S1, const Strings& S2)
{
  Strings
    S;                                       // return value

  if (S1.String_ == 0)                       // if S1 is empty
    S = S2;                                  //   we'll return S2
  else if (S2.String_ == 0)                  // else if S2 is empty
    S = S1;                                  //   we'll return S1
  else                                       // else
    {
      S.Length_ = S1.Length_ + S2.Length_;   //   set Length_
      S.String_ = new char[S.Length_+1];     //   allocate new array
      assert(S.String_ != 0);                //   verify
      strcpy(S.String_, S1.String_);         //   copy S1 into array
      strcat(S.String_, S2.String_);         //   append S2 to array
    }

  return S;                                  // return the result
}

/*--- Retrieve a substring of a Strings object.

   Receive: First, Last, two indices of this Strings object.
   Return:  The substring of this Strings object that begins at
              index First and ends at index Last.
-----------------------------------------------------------------------*/

Strings Strings::operator() (unsigned First, unsigned Last)
{
  if (Last >= Length_)                        // if Last beyond end of String
    {
      cerr << LastTooBig << "Substring.\n";   //    issue warning message
      Last = Length_ - 1;                     //     and set Last to end
    }

  if (First > Last)                           // if First not <= Last
    {
      cerr << FirstPastLast                   //    display error message
        << "Substring.\n";                    //      with function name
      exit (-1);                              //      and terminate
    }

  Strings
    S;                                        // return value

  S.Length_ = Last - First + 1;               // set its Length_ member
  S.String_ = new char[Length_ + 1];          // allocate a new array
  assert(S.String_ != 0);                     //  verify

  int
    j = First;                                // index of char to be copied

  for (int i = 0; i < S.Length_; i++)         // copy array of *this into S:
    {
      S.String_[i] = String_[j];              //   char-by-char
      j++;
    }
  S.String_[S.Length_] = '\0';                 // tack on string-terminator

  return S;                                   // return the result
}

/**** Relational Operators ************************************************

Each of these operations has a similar specification:

   Receive: S1 and S2, two Strings objects.
   Return:  True, if S1 OP S2 is true, and False, otherwise.
--------------------------------------------------------------------------*/

// --- Equality.
int operator== (const Strings& S1, const Strings& S2)
{
  if (S1.String_ == S2.String_)               // if strings are same
    return 1;                                 //    True
  else if ((S1.String_ == 0) ||               // else if either empty
           (S2.String_ == 0))
    return 0;                                 //    False
  else                                        // else use the C routine
    return (strcmp(S1.String_,S2.String_) == 0);
}

int operator== (const Strings& S1, const char* S2)
{
  if (S1.String_ == S2)                       // if strings are same
    return 1;                                 //    True
  else if ((S1.String_ == 0) ||               // else if either empty
           (S2 == 0))
    return 0;                                 //    False
  else                                        // else use the C routine
    return (strcmp(S1.String_,S2) == 0);
}

int operator== (const char* S1, const Strings& S2)
{
  if (S1 == S2.String_)                       // if strings are same
    return 1;                                 //    True
  else if ((S1 == 0) ||                       // else if either empty
           (S2.String_ == 0))
    return 0;                                 //    False
  else                                        // else use the C routine
    return (strcmp(S1,S2.String_) == 0);
}

// --- Inequality.
int operator!= (const Strings& S1, const Strings& S2)
{
  return !(S1 == S2);                         // negate == from above
}

int operator!= (const Strings& S1, const char* S2)
{
  return !(S1 == S2);                         // negate == from above
}

int operator!= (const char* S1, const Strings& S2)
{
  return !(S1 == S2);                         // negate == from above
}

//--- Less-than.
int operator< (const Strings& S1, const Strings& S2)
{
  if (S1.String_ == S2.String_)               // if strings are same
    return 0;                                 //   False
  else if (S1.String_ == 0)                   // else if S1 is empty
    return 1;                                 //   True
  else if (S2.String_ == 0)                   // else if S2 is empty
    return 0;                                 //   False
  else                                        // else apply the C routine
    return (strcmp(S1.String_, S2.String_) < 0);
}

int operator< (const Strings& S1, const char* S2)
{
  if (S1.String_ == S2)                       // if strings are same
    return 0;                                 //   False
  else if (S1.String_ == 0)                   // else if S1 is empty
    return 1;                                 //   True
  else if (S2 == 0)                           // else if S2 is empty
    return 0;                                 //   False
  else                                        // else apply the C routine
    return (strcmp(S1.String_, S2) < 0);
}

int operator< (const char* S1, const Strings& S2)
{
  if (S1 == S2.String_)                       // if strings are same
    return 0;                                 //   False
  else if (S1 == 0)                           // else if S1 is empty
    return 1;                                 //   True
  else if (S2.String_ == 0)                   // else if S2 is empty
    return 0;                                 //   False
  else                                        // else apply the C routine
    return (strcmp(S1, S2.String_) < 0);
}

// --- Greater-than.
int operator> (const Strings& S1, const Strings& S2)
{
  if (S1.String_ == S2.String_)               // if strings are the same
    return 0;                                 //   False
  else if (S1.String_ == 0)                   // else if S1 is empty
    return 1;                                 //   True
  else if (S2.String_ == 0)                   // else if S2 is empty
    return 0;                                 //   False
  else                                        // else apply the C routine
    return (strcmp(S1.String_, S2.String_) > 0);
}

int operator> (const Strings& S1, const char* S2)
{
  if (S1.String_ == S2)                       // if strings are the same
    return 0;                                 //   False
  else if (S1.String_ == 0)                   // else if S1 is empty
    return 1;                                 //   True
  else if (S2 == 0)                           // else if S2 is empty
    return 0;                                 //   False
  else                                        // else apply the C routine
    return (strcmp(S1.String_, S2) > 0);
}

int operator> (const char* S1, const Strings& S2)
{
  if (S1 == S2.String_)                       // if strings are the same
    return 0;                                 //   False
  else if (S1 == 0)                           // else if S1 is empty
    return 1;                                 //   True
  else if (S2.String_ == 0)                   // else if S2 is empty
    return 0;                                 //   False
  else                                        // else apply the C routine
    return (strcmp(S1, S2.String_) > 0);
}

// --- Less-or-equal.
int operator<= (const Strings& S1, const Strings& S2)
{
  return !(S1 > S2);                               // negate > from above
}

int operator<= (const Strings& S1, const char* S2)
{
  return !(S1 > S2);                               // negate > from above
}

int operator<= (const char* S1, const Strings& S2)
{
  return !(S1 > S2);                               // negate > from above
}

// --- Greater-or-equal.
int operator>= (const Strings& S1, const Strings& S2)
{
  return !(S1 < S2);                               // negate < from above
}

int operator>= (const Strings& S1, const char* S2)
{
  return !(S1 < S2);                               // negate < from above
}

int operator>= (const char* S1, const Strings& S2)
{
  return !(S1 < S2);                               // negate < from above
}


//***** Input/Output *********************************************

/*--- Stream input.

   Receive: InStream, an istream object;
            Str, a Strings object.
   Input:   A line of (up to MaxLength) chars from InStream;
   Return:  Str, filled with the input chars, and
            InStream.
-----------------------------------------------------------------*/

istream& operator>> (istream& InStream, Strings& Str)
{
  char
    Buffer[Strings::MaxLength];                   // temporary string storage

  InStream >> Buffer;                             // read in the string

  Str.Length_ = strlen(Buffer);                   // set Length_ member

  delete [] Str.String_;                          // remove any prior array

  Str.String_ = new char[Str.Length_+1];          // allocate new array
  assert(Str.String_ != 0);                       // verify, and
  strcpy(Str.String_, Buffer);                    // copy the buffer into it

  return InStream;                                // return the istream
}

/*--- Stream output.

   Receive: OutStream, an ostream object;
            Str, a Strings object.
   Output:  Str onto OutStream.
   Return:  OutStream.

Note: The same functions suffice for file I/O,
        since an fstream is an istream and an fstream is an ostream.
----------------------------------------------------------------------*/

ostream& operator<< (ostream& OutStream, const Strings& Str)
{
  OutStream << Str.String_;                       // output the array

  return OutStream;                               // return the ostream
}

/*--- This Strings member acts like getline for an istream...

   Receive:   In, an istream,
              MaxChars, the maximum number of chars to be read, and
              UntilChar, a delimiter char to halt the operation.
   Input(In): Up to MaxChars characters, or until UntilChar is read,
                whichever comes first.
   Return:    The Strings object containing this function,
                filled with the input characters.
              In.

Note: The same function words for a file, as an fstream is an istream.
------------------------------------------------------------------------*/

istream& Strings::GetLine(istream& In, unsigned MaxChars, char UntilChar)
{
  char
    Buffer[MaxLength];                        // temporary string storage

  In.getline(Buffer,                          // read in the line
             (MaxLength < MaxChars) ? MaxLength : MaxChars,
             UntilChar);

  Length_ = strlen(Buffer);                   // set Length_

  delete [] String_;                          // remove any prior array

  String_ = new char [Length_ + 1];           // allocate new array
  assert(String_ != 0);                       // verify, and
  strcpy(String_, Buffer);                    // copy the buffer into it

  return In;                                  // return the istream
}
