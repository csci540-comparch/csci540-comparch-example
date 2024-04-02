#ifndef PRIME_HPP
#define PRIME_HPP
#include <climits> // ULLONG_MAX defined here

// for convenience, give a new name for unsigned long long ints we use
typedef unsigned long long int bigint;

// global constants relating to primes used/generated
const bigint MAX_PRIME = ULLONG_MAX;

// functions provided by this library
bool isPrime(long long value);
bigint nextPrime(bigint prime);

#endif // PRIME_HPP