/** @file function-calls.cpp
 * @brief Example to step through a (recursive) function call/return
 *   and examine the function call stack.
 *
 * @author Derek harter
 * @note   class: CSci 540, Spring 2021
 * @note   example: Chapter 10
 * @date   March 23, 2021
 *
 * Simple example of recursive function, so can step through the function call stack.
 */
#include <iostream>
#include <string>
using namespace std;

/** factorial
 * Calculate n! using recursive function.
 * 
 * @param n The number to calculate n! (n factorial) of.
 *
 * @returns int Returns the result of calculating n!.
 */
int factorial(int n)
{
  int nMinusOneResult;
  
  // base case, 0! is defined as 1
  if (n == 0)
  {
    return 1;
  }

  // otherwise calculate factorial recursively
  // notice: uses tail recursion
  nMinusOneResult = factorial(n - 1);
  return n * nMinusOneResult;
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

  // test base case, 0! should be 1
  cout << "0 factorial: " << factorial(0) << endl;

  // test a harder case, 5! = 5*4*3*2*1 = 120
  cout << "5 factorial: " << factorial(5) << endl;
  
  // return 0 to indicate successful program completion
  return 0;
}
