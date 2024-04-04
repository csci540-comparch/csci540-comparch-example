/**
 * @file exec.c
 * @brief Linux process management system calls
 *
 * Program used in fork/exec example.  When called this
 * program will echo all of its command line arguments first,
 * then it accesses its environment variables and echos
 * all of them.  This is to demonstrate passing in command
 * arguments and environment variables to this process.
 *
 * Examples from Richard (2013) "Advanced Programming in the UNIX Environment" 3ed
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
  int i;
  char** ptr;
  extern char** environ;

  // echo all command line arguments passed in argv
  for (i = 0; i < argc; i++)
  {
    printf("argv[%d]: %s\n", i, argv[i]);
  }

  // access and echo out all environment variables
  for (ptr = environ; *ptr != 0; ptr++)
  {
    printf("%s\n", *ptr);
  }

  // this process returns an explicit exit status code back to parent on exit
  exit(42);
}
