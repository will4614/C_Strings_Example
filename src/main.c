//***************************************************************************
// File name:		main.c
// Author:			chadd williams
// Date:				September 24, 2021
// Class:				CS 360
// Purpose:			Demonstrate strncat and snprintf
//***************************************************************************

#include <stdio.h>
#include <string.h> 
#include <stdlib.h>

/****************************************************************************
 Function:		main
 
 Description:	Use strncat and snprintf to build null termianted strings
 
 Parameters:	none

 Returned:		EXIT_SUCCESS
****************************************************************************/
int main()
{

  const int BUFFER_SIZE = 1024;
  const int SMALL_ST_SIZE = 15;

  char szBuffer[BUFFER_SIZE];
  char szSmallString[SMALL_ST_SIZE];


  // null terminate both empty strings
  szBuffer[0] = '\0';
  szSmallString[0]='\0';


  // destination: szSmallString
  // source: "Hello:"
  // number of characters to copy from src to dest:
  // Size of the dest string MINUS ONE
  // the minus one is to reserve space for the NULL '\0'
  // character.
  strncat(szSmallString, "Hello:", SMALL_ST_SIZE - 1);

  printf("szSmallString: %s\n\n", szSmallString);

  // Now, szSmallString contains data so 
  // strncat will put the new string, " CS360!", after
  // the existing data in szSmallString
  //
  // Since there is already data in szSmallString we 
  // can copy fewer bytes over from the src string.
  strncat(szSmallString, " CS360!", (SMALL_ST_SIZE - strlen(szSmallString)) - 1 );

  printf("szSmallString: %s\n\n", szSmallString);


  // destination: szBuffer
  // size: BUFFER_SIZE
  // format string: "MSG TXT ..."
  // variables: szSmallString
  snprintf(szBuffer, BUFFER_SIZE, "MSG TXT 1.1\r\n%s\r\n", szSmallString);

  printf("szBuffer: \n%s\n\n", szBuffer);

  return EXIT_SUCCESS;
}