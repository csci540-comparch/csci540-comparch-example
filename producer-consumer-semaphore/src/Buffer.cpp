#include "Buffer.hpp"

/**
 * @brief Buffer default constructor
 *
 * Basic constructor, dynamically allocate the public buffer array.
 */
Buffer::Buffer() : filled(0), available(100)
{
  in = 0;
  out = 0;
  buffer = new bigint[BUF_SIZE];
}

/**
 * @brief Calculate next index for circular buffer
 *
 * Given a pointer/index, calculate the next index after this
 * value.  This is just k+1 unless that value is past the end
 * of the buffer, in which case we wrap back around and
 * return 0.
 *
 * @param k The value to calculate next index from
 *
 * @returns int Returns next value in circular buffer, which is k+1 unless
 *   the buffer wraps back around to 0.
 */
int Buffer::next(int k)
{
  if (k < BUF_SIZE - 1)
    return k + 1;
  else
    return 0;
}