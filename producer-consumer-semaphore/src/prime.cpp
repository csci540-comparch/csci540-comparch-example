#include "prime.hpp"
#include <cmath>

/**
 * @brief Test if a value is prime
 *
 * Given a long integer value, test if the value is a prime number.
 * We use a brute force implementation to test all possible divisors
 * from 2 up to sqrt(value), and if we find a divisor in that range
 * the number is not prime, but if no divisor evenly divides the
 * value, then the number is (presumed) prime
 *
 * @param value The value to test for "primeness"
 *
 * @returns bool True if the value is a prime number, false if the
 *   value is not prime.
 */
bool isPrime(long long value)
{
  // brute force search for a divisor of the value
  for (bigint divisor = 2; divisor <= sqrt(value); divisor++)
  {
    // if divisor evently divides value, answer is false, this is not a prime
    if (value % divisor == 0)
    {
      return false;
    }
  }
  // otherwise no divisor from 2 up to sqrt(value) evenly divides, which should
  // ensure that the number has no divisor except 1 and itself
  return true;
}

/**
 * @brief generate next prime
 *
 * Given the value of the current prime, start searching for the next
 * largest prime from value + 1.
 *
 * @param prime The value of the current prime to start searching from.
 *
 * @returns bigint Returns the next largest prime above the initial prime
 *   given to this function.
 */
bigint nextPrime(bigint prime)
{
  prime++;
  while (not isPrime(prime))
  {
    prime++;
  }
  return prime;
}
