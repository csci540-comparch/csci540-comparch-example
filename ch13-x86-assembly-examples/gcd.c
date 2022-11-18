#include <stdio.h>

// function prototype for hand written assembly version
unsigned int gcd2(unsigned int a, unsigned int b);

unsigned int gcd(unsigned int a, unsigned int b)
{
  if (a == 0 && b == 0)
  {
    b = 1;
  }
  else if (b == 0)
  {
    b = a;
  }
  else if (a != 0)
  {
    while (a != b)
    {
      printf("<gcd> in loop a=%d b=%d\n", a, b);
      if (a < b)
      {
        b -= a;
      }
      else
      {
        a -= b;
      }
    }
  }

  return b;
}

int main(int argc, char** argv)
{
  unsigned int divisor;

  // calls the c version of function named gcd
  // test base cases
  divisor = gcd(0, 0);
  printf("gcd2(0, 0) = %d\n", divisor);

  // gcd of 0 and some other number is that other number, so expect 5 here
  divisor = gcd(0, 5);
  printf("gcd2(0, 5) = %d\n", divisor);

  // gcd with second value being 0 should still be 5
  divisor = gcd(5, 0);
  printf("gcd2(5, 0) = %d\n", divisor);

  // no common divisor so answer is 1
  divisor = gcd(5, 4);
  printf("gcd(5, 4) = %d\n", divisor);

  // a number is a divisor of itself so answer is 5
  divisor = gcd(5, 5);
  printf("gcd(5, 5) = %d\n", divisor);

  // answer is 30 here
  divisor = gcd(360, 210);
  printf("gcd(360, 210) = %d\n", divisor);

  // calls the hand written assembly version
  // by definition, gcd of 0 and 0 should be 1
  divisor = gcd2(0, 0);
  printf("gcd2(0, 0) = %d\n", divisor);

  // gcd of 0 and some other number is that other number, so expect 5 here
  divisor = gcd2(0, 5);
  printf("gcd2(0, 5) = %d\n", divisor);

  // gcd with second value being 0 should still be 5
  divisor = gcd2(5, 0);
  printf("gcd2(5, 0) = %d\n", divisor);

  // no common divisor so answer is 1
  divisor = gcd2(5, 4);
  printf("gcd2(5, 4) = %d\n", divisor);

  // a number is a divisor of itself so answer is 5
  divisor = gcd2(5, 5);
  printf("gcd2(5, 5) = %d\n", divisor);

  // answer is 30 here
  divisor = gcd2(360, 210);
  printf("gcd2(360, 210) = %d\n", divisor);
}