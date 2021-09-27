//***************************************************************************
// File name:		main.c
// Author:			chadd williams
// Date:				September 26, 2021
// Class:				CS 360
// Purpose:			Demonstrate strncpy, strncat, memset, strstr, isdigit, atoi
//***************************************************************************

#include <stdio.h>
#include <string.h> 
#include <stdlib.h>
#include <ctype.h>

/****************************************************************************
 Function:		main
 
 Description:	Build large strings and search for substrings
 
 Parameters:	none

 Returned:		EXIT_SUCCESS
****************************************************************************/

int main()
{
  const char* RO_STR = "Hello CS 360. Max: 28 Students\nHave fun!\n\n";
  const int BUF_SIZE = 1024;
  const int SM_BUF_SIZE = 15;

  char szBuffer[BUF_SIZE];
  char szSmBuffer[SM_BUF_SIZE];
  char *pStr;
  char *pEnd;

  int value;
  char tmpChar;


  // set all of szSmBuffer to '\0'
  memset(szSmBuffer, '\0', SM_BUF_SIZE);

  // use strncat to copy the first 13 bytes
  // from RO_STR to szSmBuffer

  // NOTE: this strncpy does NOT put a \0 
  // at the end of the data. We had to 
  // put the \0 using memset!
  // also, we know 13 < SM_BUF_SIZE
  strncpy(szSmBuffer, RO_STR, 13);

  // szSmBuffer now looks like:
  // Hello CS 360.\0\0
  printf("0. szSmBuffer: >|%s|<\n\n", szSmBuffer);

  // use strncpy to copy RO_STR into
  // szBuffer

  // copy at most BUF_SIZE bytes from RO_STR
  // to szBuffer.
  // Since the \0 in RO_STR happens in 
  // the first BUF_SIZE bytes, the \0 is
  // copied to szBuffer.

  strncpy(szBuffer, RO_STR, BUF_SIZE);

  printf("1. szBuffer >|%s|<\n\n", szBuffer);

  // use strncat to copy RO_STR on to
  // the end of szBuffer

  strncat(szBuffer, RO_STR, BUF_SIZE - strlen(szBuffer) - 1);

  printf("2. szBuffer >|%s|<\n\n", szBuffer);

  // use strstr to find Max: in szBuffer
  pStr = strstr(szBuffer, "Max:");

  if ( NULL == pStr )
  {
    printf("ERROR: Max: NOT FOUND!\n\n");
  }
  else
  {
    // found Max:
    // pStr now points to the point in szBuffer
    // that contains the first Max:
    printf("3. pStr >|%s|<\n\n", pStr);

    // find the first digit past Max:
    while ( !isdigit(*pStr))
    {
      ++ pStr;
    }

    // use pEnd to walk the string to
    // find the end of the digits '28'.
    pEnd = pStr;

    while ( isdigit(*pEnd))
    {
      ++ pEnd;
    } 

    // Now pStr points to the first digit in 28
    // and pEnd points to the first character past
    // the last digit. In this case, a space.

    // print the char pStr points to, so use the *
    printf("4. pStr >|%c|< pEnd >|%c|<\n\n", *pStr, *pEnd);

    // turn the text into an int using atoi
    // atoi requires a NULL terminated string
    // that only contains digits.

    // We need to NULL terminate the digits
    // by replacing the space with a \0.
    // Let's save the space in a temp char
    tmpChar = *pEnd;

    // replace the space with at NULL 
    *pEnd = '\0';

    // Now, the string that starts at pStr
    // is NULL terminated. 
    // Let's check. We know printf prints
    // until a \0 is found.
    printf("5. pStr >|%s|<\n\n", pStr);

    // Let's check szBuffer too!
    printf("6. szBuffer >|%s|<\n\n", szBuffer);

    // now call atoi
    value = atoi(pStr);

    // restore the space
    *pEnd = tmpChar;

    // print the int!
    printf("7. value: >|%d|<\n\n", value);

    // print szBuffer after restoring the space
    printf("8. szBuffer >|%s|<\n\n", szBuffer);
  }



  return EXIT_SUCCESS;
}