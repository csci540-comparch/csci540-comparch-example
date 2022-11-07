/** @file ch12-littendian.cpp
 * @brief Example of little-endian layout on Intel x86_64 architecture
 *
 * @author Derek harter
 * @note   class: CSci 540, Spring 2021
 * @note   example: Chapter 10
 * @date   March 23, 2021
 *
 * Example layout of a structure of various sizes/types on the
 * machine architecture we are compiled on.  Also demonstrates
 * C/C++ alignment of data types on 4 bytes (32-bit) boundaries.
 */
#include <iostream>
#include <string>
using namespace std;

typedef union {double f; uint64_t i;} doubleu;
struct LittleEndian
{
  int a;
  int pad;
  doubleu b;
  char* c;
  char d[7];
  short e;
  int f;
};

/** main
 * The main entry point for this program.  Execution of this program
 * will begin with this main function.
 *
 * @param argc The command line argument count which is the number of
 *     command line arguments provided by user when they started
 *     the program.
 * @param argv The command line arguments, an array of character
 *     arrays.
 *
 * @returns An int value indicating program exit status.  Usually 0
 *     is returned to indicate normal exit and a non-zero value
 *     is returned to indicate an error condition.
 */
int main(int argc, char** argv)
{
  char c = 'X';
  LittleEndian s;

  // initialze member fiels of structure s
  s.a = 0x11121314;
  s.pad = 0;
  s.b.i = 0x2122232425262728;
  
  s.c = &c;
  
  s.d[0] = 'A';
  s.d[1] = 'B';
  s.d[2] = 'C';
  s.d[3] = 'D';
  s.d[4] = 'E';
  s.d[5] = 'F';
  s.d[6] = 'G';
  
  s.e = 0x5152;
  s.f = 0x61626364;

  cout << "s.b: " << s.b.f << endl;
  cout << "&c :" << hex << static_cast<void*>(s.c) << endl;

  // return 0 to indicate successful program completion
  return 0;
}
