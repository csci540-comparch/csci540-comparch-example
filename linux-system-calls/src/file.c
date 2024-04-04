/**
 * @file file.c
 * @brief Linux file system calls
 *
 * Example of file system calls.  Use basic calls open(), read(),
 * write() and close() in this example.
 *
 * Examples from Richard (2013) "Advanced Programming in the UNIX Environment" 3ed
 */
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define RWRWRW (S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH)

int main(int argc, char** argv)
{
  // open opens or creates a file, we use mode here to open for reading and writing
  // files in unix/linux use a file descriptor, which is returned by open and used by
  // all other calls to determine which file to operate on.
  int fd;
  fd = open("./examplefile.txt", O_RDWR | O_CREAT, RWRWRW);
  if (fd < 0) // retuns negative value as fd on failure to open
  {
    printf("Error couldn't open file\n");
    exit(1);
  }

  // write some data to the file
  ssize_t numwrite;
  char* data = "This is some example data, we write out a string of ascii encoded bytes\n";
  numwrite = write(fd, data, strlen(data));
  printf("We wrote the number of bytes to the file: %ld\n", numwrite);

  // after write, location in file is at end of data we just wrote,
  // position back to beginning of file so we can read some data back
  off_t offset;
  offset = lseek(fd, 0, SEEK_SET);
  printf("We seeked from begin of file offset: %ld\n", offset);
  
  // read some of the data back out we just wrote
  ssize_t numread;
  char buffer[8];
  numread = read(fd, buffer, 7);
  buffer[7] = '\0'; // null terminate so can treat as string
  printf("Read back in number of bytes: %ld\n", numread);
  printf("Data we read: <%s>\n", buffer);
  
  // close the opened file, this frees up resources allocated by OS and ensures buffered
  // data is written out to secondary storage
  int status;
  status = close(fd);
  if (status < 0)
  {
    printf("Error couldn't close file\n");
  }
  
  exit(0);
}
