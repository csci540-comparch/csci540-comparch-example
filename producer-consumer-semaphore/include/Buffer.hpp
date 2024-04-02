#ifndef BUFFER_HPP
#define BUFFER_HPP
#include "prime.hpp"
#include <semaphore>
#include <thread>

using namespace std;

// global constants used by Buffer class
const int BUF_SIZE = 100;

/**
 * @brief Basic buffer for producer/consumer
 *
 * Create a class to hold a circular buffer of values for producer/consumer
 * threads to access and manipulate.  We call this class Buffer where it was
 * called simply m in the original textbook example.  We don't really use this
 * as a class, we set the buffer and in/out pointers to be public members
 * that can be directly accessed and manipulated by the users of this
 * buffer.
 */
class Buffer
{
public:
  int in;
  int out;
  bigint* buffer;
  counting_semaphore<BUF_SIZE> filled;
  counting_semaphore<BUF_SIZE> available;


  Buffer();
  int next(int k);
};

#endif // BUFFER_HPP