#ifndef CONSUMER_HPP
#define CONSUMER_HPP
#include "Buffer.hpp"
#include "Producer.hpp"
#include "Resumable.hpp"
#include <iostream>

// forward declaration needed for recursive dependencies of Producer/Consumer
class Producer;

/**
 * @brief Consumer of primes
 *
 * Class that implements the Producer in the producer/consumer
 * circular buffer race condition example.  We are given the
 * buffer object when the object is constructed.  While running,
 * this thread consumes and display primes out of the circular
 * buffer.
 */
class Consumer : public Resumable
{
public:
  Consumer();
  void run();
  void setBuffer(Buffer* buffer);
  void setProducer(Producer* producer);

private:
  /// We are given an instance of the circular buffer we are to use when
  /// the Producer is created
  Buffer* buffer;

  /// We are given a handle to the Consumer we are working with so that we can
  /// resume them if we make the buffer non empty again
  Producer* producer;

  int consumerPauseCount;
  int producerResumeCount;
};

#endif // CONSUMER_HPP