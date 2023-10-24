/** @file ch10-computer-arithmetic.cpp
 * @brief Examples of int and float formats
 *
 * @author Derek harter
 * @note   class: CSci 540, Spring 2021
 * @note   example: Chapter 10
 * @date   March 23, 2021
 *
 * Examples of integer and float representations from our Stallings chapter 10
 * chapter on computer arithmetic and numerical data representations in
 * computer architectures.
 */
#include <bitset>
#include <cmath>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

/** to 32-bit float representation
 * Given 32 bits that represent a standard IEEE 754 32-bit float.  Create a
 * string that displays the bits of the Sign (1 bit), Exponent (8 bits) and
 * Significand (23 bits), and return that string representation.
 *
 * @param floatRepresentation A set of 32 bits representing a float in memory.
 *   Needs to be input to this function by casing to a uint32_t type.
 *
 * @returns string Returns a string representation of the Sign, Exponent and
 *   significand bits of the given float representation.
 */
string floatToBitString(uint32_t floatRepresentation)
{
  ostringstream out;

  // first we'll create a bitset so we can easily extract the bits.
  bitset<32> bits = bitset<32>(floatRepresentation);

  // extract sign bit, which is at bit position 31 (most significant)
  out << "sign: " << bits[31];

  // extract the exponent bits, which are next 8 bits in positions 30-23
  out << " E:";
  for (int bitpos = 30; bitpos >= 23; bitpos--)
  {
    // put a space between every 4 bits in output
    if ((bitpos + 2) % 4 == 0)
    {
      out << " ";
    }

    // add the bit to the output stream
    out << bits[bitpos];
  }

  // extract the significand bits which are next 23 bits in positions 22-0
  out << " S:";
  for (int bitpos = 22; bitpos >= 0; bitpos--)
  {
    // put a space between every 4 bits in output
    if ((bitpos + 2) % 4 == 0)
    {
      out << " ";
    }

    // add the bit to output stream
    out << bits[bitpos];
  }

  // return the resulting constructed string
  return out.str();
}

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

  // lets start by examining unsigned integer values with only 8 bits
  cout << "------------------ unsigned 8-bit integers ----------------" << endl;

  char x1;

  // q: why 48 bit memory addresses?
  // https://stackoverflow.com/questions/6716946/why-do-x86-64-systems-have-only-a-48-bit-virtual-address-space
  cout << "sizeof x1: " << sizeof(x1) << endl << "address of x1:" << hex << static_cast<void*>(&x1) << dec << endl << endl;

  x1 = 'a';
  cout << "value of x1: " << x1 << endl;
  cout << "value of x1: " << dec << (int)x1 << " (decimal)" << endl;
  cout << "value of x1: " << bitset<8>(x1) << " (binary)" << endl << endl;

  uint8_t x2;

  cout << "sizeof x2: " << sizeof(x2) << endl << "address of x2: " << hex << static_cast<void*>(&x2) << dec << endl << endl;

  x2 = 0;
  cout << "value of x2: " << dec << (int)x2 << " (decimal) " << endl;
  cout << "value of x2: " << bitset<8>(x2) << " (binary)" << endl << endl;

  x2 = 0xFF;
  cout << "value of x2: " << dec << (int)x2 << " (decimal) " << endl;
  cout << "value of x2: " << bitset<8>(x2) << " (binary)" << endl << endl;

  x2 = -1;
  cout << "value of x2: " << dec << (int)x2 << " (decimal) " << endl;
  cout << "value of x2: " << bitset<8>(x2) << " (binary)" << endl << endl;

  // lets try a signed 8-bit integer now, and see the difference
  cout << "---------- signed 8-bit integers (2s complement) ----------" << endl;

  int8_t x3;

  cout << "sizeof x3: " << sizeof(x3) << endl << "address of x3: " << hex << static_cast<void*>(&x3) << dec << endl << endl;

  x3 = 0;
  cout << "value of x3: " << dec << (int)x3 << " (decimal) " << endl;
  cout << "value of x3: " << bitset<8>(x3) << " (binary)" << endl << endl;

  x3 = 97;
  cout << "value of x3: " << dec << (int)x3 << " (decimal) " << endl;
  cout << "value of x3: " << bitset<8>(x3) << " (binary)" << endl << endl;

  x3 = -97;
  cout << "value of x3: " << dec << (int)x3 << " (decimal) " << endl;
  cout << "value of x3: " << bitset<8>(x3) << " (binary)" << endl << endl;

  // unsigned 32-bit integer
  cout << "----------------- unsigned 32-bit integers ----------------" << endl;

  unsigned int x4;

  cout << "sizeof x4: " << sizeof(x4) << endl << "address of x4: " << hex << static_cast<void*>(&x4) << dec << endl << endl;

  x4 = 0;
  cout << "value of x4: " << dec << (int)x4 << " (decimal) " << endl;
  cout << "value of x4: " << bitset<32>(x4) << " (binary)" << endl << endl;

  x4 = 97;
  cout << "value of x4: " << dec << (int)x4 << " (decimal) " << endl;
  cout << "value of x4: " << bitset<32>(x4) << " (binary)" << endl << endl;

  // what happens if you try and put a negative value into an unsigned integer?
  x4 = -97;
  cout << "value of x4: " << dec << (int)x4 << " (decimal) " << endl;
  cout << "value of x4: " << dec << (uint)x4 << " (unsigned decimal) " << endl;
  cout << "value of x4: " << bitset<32>(x4) << " (binary)" << endl << endl;

  // maximum unsigned 32-bit int is...
  x4 = 0xFFFFFFFF;
  cout << "value of x4: " << dec << (int)x4 << " (decimal) " << endl;
  cout << "value of x4: " << dec << (uint)x4 << " (unsigned decimal) " << endl;
  cout << "value of x4: " << bitset<32>(x4) << " (binary)" << endl;
  cout << "2^32 = " << pow(2, 32) << endl << endl;

  // signed 32-bit integer
  cout << "------------------ signed 32-bit integers -----------------" << endl;

  int x5;

  cout << "sizeof x5: " << sizeof(x5) << endl << "address of x5: " << hex << static_cast<void*>(&x5) << dec << endl << endl;

  x5 = 97;
  cout << "value of x5: " << dec << (int)x5 << " (decimal) " << endl;
  cout << "value of x5: " << bitset<32>(x5) << " (binary)" << endl << endl;

  // what happens if you try and put a negative value into an signed integer?
  x5 = -97;
  cout << "value of x5: " << dec << (int)x5 << " (decimal) " << endl;
  cout << "value of x5: " << dec << (uint)x5 << " (unsigned decimal) " << endl;
  cout << "value of x5: " << bitset<32>(x5) << " (binary)" << endl << endl;

  // Q: What is maximum number you can represent in 32-bit signed int?
  // A: sign bit 0, followed by 31 bits set to 1
  x5 = 0X7FFFFFFF;
  cout << "value of x5: " << dec << (int)x5 << " (decimal) " << endl;
  cout << "value of x5: " << dec << (uint)x5 << " (unsigned decimal) " << endl;
  cout << "value of x5: " << bitset<32>(x5) << " (binary)" << endl << endl;

  // Q: What is minimum number you can represent in 32-bit signed int?
  // A: sign bit 1, followed by 31 bits set to 0
  x5 = 0X80000000;
  cout << "value of x5: " << dec << (int)x5 << " (decimal) " << endl;
  cout << "value of x5: " << dec << (uint)x5 << " (unsigned decimal) " << endl;
  cout << "value of x5: " << bitset<32>(x5) << " (binary)" << endl << endl;

  // standard 32-bit float
  cout << "------------------ standard 32-bit float ------------------" << endl;

  // we need to be a bit tricky to get the actual bit pattern using bitset.
  // bitset will cast a float to an int and give bitpattern of that.  So
  // we use a union, set the floating point or a bit pattern, then
  // create binary representation using bitset from the interpretation as
  // uint_32 set of bits
  union
  {
    float f;
    uint32_t i;
  } x6;
  // float x6;

  cout << "sizeof x6: " << sizeof(x6) << endl << "address of x6: " << hex << static_cast<void*>(&x6) << dec << endl << endl;

  // Q: does representation of 0 look like stated in our textbook?
  x6.f = 0;
  // x6.i = 0xC2340000;
  //  x6.f = 0.645;
  cout << "value of x6: " << dec << (float)x6.f << " (decimal) " << endl;
  cout << "value of x6: " << endl << "     " << floatToBitString(x6.i) << " (binary)" << endl << endl;

  // While were at it, can we see how -0 is displayed?
  // whoops, that doesn't work, I wonder why not...
  // x6.i = 0x80000000;
  x6.f = -0.0;
  cout << "value of x6: " << dec << (float)x6.f << " (decimal) " << endl;
  cout << "value of x6: " << endl << "     " << floatToBitString(x6.i) << " (binary)" << endl << endl;

  // lets see how 5.5 is represented, recall in binary this would be 101.1
  // which is 1.011 x 2^2
  x6.f = 5.5;
  cout << "value of x6: " << dec << (float)x6.f << " (decimal) " << endl;
  cout << "value of x6: " << endl << "     " << floatToBitString(x6.i) << " (binary)" << endl << endl;

  // lets see how -5.5 is represented, recall in binary this would be 101.1
  // which is 1.011 x 2^2
  x6.f = -5.5;
  cout << "value of x6: " << dec << (float)x6.f << " (decimal) " << endl;
  cout << "value of x6: " << endl << "     " << floatToBitString(x6.i) << " (binary)" << endl << endl;

  // recall maximum value we can represent will be when exponent is all 1's, and
  // when significand is all 1's.  What is that value?
  // but that is the special quiet NaN
  x6.i = 0x7FFFFFFF;
  cout << "value of x6: " << dec << (float)x6.f << " (decimal) " << endl;
  cout << "value of x6: " << endl << "     " << floatToBitString(x6.i) << " (binary)" << endl << endl;

  // and positive infinity
  x6.i = 0x7F800000;
  cout << "value of x6: " << dec << (float)x6.f << " (decimal) " << endl;
  cout << "value of x6: " << endl << "     " << floatToBitString(x6.i) << " (binary)" << endl << endl;

  // so before we try and get the max value, lets demonstrate negative infinity,
  x6.i = 0xFF800000;
  cout << "value of x6: " << dec << (float)x6.f << " (decimal) " << endl;
  cout << "value of x6: " << endl << "     " << floatToBitString(x6.i) << " (binary)" << endl << endl;

  // Back to largest number.  Anytime exponent is all 1's, these are interpreted
  // as special values infinity or NaN.  So the maximum exponent we can
  // have is 7 1's with a 0 for the exaponent, and all 1s for Significand.
  // this means we have bit pattern
  //
  //     0 1111 1110 1111 1111 1111 1111 1111 111
  //
  // Regrouping gives us:
  //
  //     0111 1111 0111 1111 1111 1111 1111 1111
  x6.i = 0x7F7FFFFF;
  cout << "value of x6: " << dec << (float)x6.f << " (decimal) " << endl;
  cout << "value of x6: " << endl << "     " << floatToBitString(x6.i) << " (binary)" << endl << endl;

  // what happens if overflow?
  // notice, this doesn't actually change the result, because doesn't effect the
  // 23 significant digits
  x6.f += 1;
  cout << "value of x6: " << dec << (float)x6.f << " (decimal) " << endl;
  cout << "value of x6: " << endl << "     " << floatToBitString(x6.i) << " (binary)" << endl << endl;

  // notice, this didn't actually change the result, because doesn't effect the
  // 23 significant digits.  To effect result need a value big enough to
  // effect the significant digits.
  x6.f += 0.000001e38;
  cout << "value of x6: " << dec << (float)x6.f << " (decimal) " << endl;
  cout << "value of x6: " << endl << "     " << floatToBitString(x6.i) << " (binary)" << endl << endl;

  // largest negative number
  x6.i = 0xFF7FFFFF;
  cout << "value of x6: " << dec << (float)x6.f << " (decimal) " << endl;
  cout << "value of x6: " << endl << "     " << floatToBitString(x6.i) << " (binary)" << endl << endl;

  // smallest positive number before underflow is then all 0's for exponent, and a
  // significand that as small as possible, but again if significan is all 0's and
  // exponent is all 0's this is interpreted as a 0.
  x6.i = 0x00000001;
  cout << "value of x6: " << dec << (float)x6.f << " (decimal) " << endl;
  cout << "value of x6: " << endl << "     " << floatToBitString(x6.i) << " (binary)" << endl << endl;

  // what happens if underflow?
  x6.f -= 1.0e-45;
  cout << "value of x6: " << dec << (float)x6.f << " (decimal) " << endl;
  cout << "value of x6: " << endl << "     " << floatToBitString(x6.i) << " (binary)" << endl << endl;

  // return 0 to indicate successful completion of program
  return 0;
}
