#include <stdio.h>
#include <string.h> 

int main()
{

  const int BUFFER_SIZE = 1024;
  const int SMALL_ST_SIZE = 50;

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


}