/** @file assg04-cache-performance.cpp
 *
 * @brief Assignment 04 Question 1
 *
 * @author Derek Harter
 * @note   cwid: 123456
 * @date   Fall 2022
 * @note   ide:  g++ 8.2.0 / GNU Make 4.2.1
 *
 * Given two implementations of calculating the squared
 * difference of an array of values, demonstrate performance
 * implications that result from cacheing issues for the
 * two separate versions of the calculation.
 */
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>

using namespace std;

/**
 * @brief Squared Difference Program A
 *
 * Calculate the squared difference using Program code snippet BA
 * from the assignment.  Implement as a single loop with the
 * difference then squaring occurring together in the loop.
 *
 * @param n The number of values in the given arrays X, Y and Z
 * @param X An array of size n of double values
 * @param Y An array of size n of double values
 * @param Z An array of size n of double results, holds resulting
 *    calculation Z = (X - Y)^2
 */
void squaredDifferenceVersionA(int n, double X[], double Y[], double Z[])
{
  int i;

  // use single loop to calculate both difference and square it in the loop
  for (i = 0; i < n; i++)
  {
    Z[i] = X[i] - Y[i];
    Z[i] = Z[i] * Z[i];
  }
}

/**
 * @brief Squared Difference Program B
 *
 * Calculate the squared difference using Program code snippet B
 * from the assignment.  Implement calculation in two separate
 * loops.
 *
 * @param n The number of values in the given arrays X, Y and Z
 * @param X An array of size n of double values
 * @param Y An array of size n of double values
 * @param Z An array of size n of double results, holds resulting
 *    calculation Z = (X - Y)^2
 */
void squaredDifferenceVersionB(int n, double X[], double Y[], double Z[])
{
  int i;

  // initial loop calculates the difference of the values Z = X - Y
  for (i = 0; i < n; i++)
  {
    Z[i] = X[i] - Y[i];
  }

  // now calculate the square of the differences from previous calculation Z = Z^2
  for (i = 0; i < n; i++)
  {
    Z[i] = Z[i] * Z[i];
  }
}

/**
 * @brief time a function
 *
 * Given a function to run, time the function using chrono high
 * resolution clock to determine elapsed wall clock (real) time
 * that the function takes to run.
 *
 * @param function A pointer to the function to invoke
 * @param n The number of values to allocate and test with, to be passed
 *   to the function we are to invoke.
 * @param X An array of x values to be passed to the function we are invoking.
 * @param Y An array of y values to be passed to the function we are invoking.
 * @param Z An array of z results to be passed to the function we are invoking.
 *
 * @returns double Returns the elapsed time that the function
 *   took to complete its task.
 */
double timeit(void (*function)(int, double*, double*, double*), int n, double X[], double Y[], double Z[])
{
  double elapsedTime;

  auto start = chrono::high_resolution_clock::now();
  (*function)(n, X, Y, Z);
  auto end = chrono::high_resolution_clock::now();

  elapsedTime = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
  return elapsedTime;
}

/**
 * @brief initialize arrays
 *
 * Initialize input arrays to random values for tests, and initialize result
 * array to all 0's.  Calling this funciton before performing the calculations
 * also ensures cache memory is in a similar state before beginning calculations.
 *
 * @param n The number of values in the arrays to initialize.
 * @param X The array of X to initialize to random values.
 * @param Y The array of Y to initialize to random values.
 * @param Z The result array to be initialized to 0 values.
 */
void initializeArrays(int n, double X[], double Y[], double Z[])
{
  for (int i = 0; i < n; i++)
  {
    X[i] = ((double)rand() / (RAND_MAX)); // random value from 0.0 to 1.0
    Y[i] = ((double)rand() / (RAND_MAX)); // random value from 0.0 to 1.0
    Z[i] = 0.0;
  }
}

/**
 * @brief A/B test algorithms for size n
 *
 * Test the two different versions of our algorithm for a given size
 * n of values to perform the calculation with.
 *
 * @param n The number of values to allocate and test with.
 * @param numTrials The number of independent trials to perform and
 *   measure the elapsed time of.
 *
 */
void testVersions(int n, int numTrials)
{
  // array of values to be used for calculations
  double* X;
  double* Y;
  double* Z;

  // values to calculate average elapsed time of performing calculations/functions
  double elapsedTime;
  double totalTime;
  double averageA;
  double averageB;
  double speedup;

  // dynamically allocate arrays of the given size for the calculations
  X = new double[n];
  Y = new double[n];
  Z = new double[n];

  // not necessary to initialize, but this will ensure values are cached same for A and B
  initializeArrays(n, X, Y, Z);

  // test trials with version A of calculation
  cout << "Perform Calculation A (1 loop faster) with n = " << n << endl;
  totalTime = 0.0;
  for (int trial = 1; trial <= numTrials; trial++)
  {
    // cout << "Calculation A Trial: " << trial << " ";
    elapsedTime = timeit(squaredDifferenceVersionA, n, X, Y, Z);
    totalTime += elapsedTime;
    // cout << "time: " << fixed << elapsedTime << " ns" << endl;
  }
  averageA = totalTime / numTrials;
  cout << "Average elapsed time: " << fixed << averageA << " ns" << endl;
  cout << endl;

  // not necessary to initialize, but this will ensure values are cached same for A and B
  initializeArrays(n, X, Y, Z);

  // test trials with version B of calculation
  cout << "Perform Calculation B (2 loops slower) with n = " << n << endl;
  totalTime = 0.0;
  for (int trial = 1; trial <= numTrials; trial++)
  {
    // cout << "Calculation B Trial: " << trial << " ";
    elapsedTime = timeit(squaredDifferenceVersionB, n, X, Y, Z);
    totalTime += elapsedTime;
    // cout << "time: " << fixed << elapsedTime << " ns" << endl;
  }
  averageB = totalTime / numTrials;
  cout << "Average elapsed time: " << fixed << averageB << " ns" << endl << endl;

  // determine the speedup, the ratio of the slower to the faster performaning versions
  speedup = averageB / averageA;
  cout << "Speedup: " << speedup << endl;
  cout << endl;

  // deallocate the memory we will no longer be needing
  delete[] X;
  delete[] Y;
  delete[] Z;
}

/**
 * @brief main entry
 *
 * Main entry point of process when run.  Code execution starts here.
 * Whenever a process is created, it is initially created with a single
 * thread.  The main() function starting point is the code that
 * will initially be executing in the initial thread.
 *
 * @param argc The count of the number of arguments on the command line.
 * @param argv[] An array of char* strings, the command line arguments
 *   provided by the user when this program is run.
 *
 * @returns int Returns a status/exit code.  0 means normal termination.
 */
int main(int argc, char* argv[])
{
  // With size 10, no extra caching should occur
  int n = 10;
  int numTrials = 100'000'000;
  cout << "=============== n = " << n << " numTrials = " << numTrials << " ===============" << endl;
  testVersions(n, numTrials);
  cout << endl << endl;

  // but with n=1e6, this will not fit in all cache levels
  n = 1'000'000;
  numTrials = 1000;
  cout << "=============== n = " << n << " numTrials = " << numTrials << " ===============" << endl;
  testVersions(n, numTrials);
  cout << endl << endl;

  // return 0 to indicate successful completion
  return 0;
}
