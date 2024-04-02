#ifndef PRODUCER_HPP
#define PRODUCER_HPP
#include "Buffer.hpp"
#include "Consumer.hpp"
#include "Resumable.hpp"

// forward declaration needed for recursive dependencies of Producer/Consumer
class Consumer;

/**
 * @brief Producer of primes
 *
 * Class that implementes the Producer in the producer/consumer
 * circular buffer race condition example.  We are given the
 * buffer object when the object is constructed.  While
 * running, this thread basically keeps generating primes
 * and adding them to the circular buffer.
 */
class Producer : public Resumable
{
public:
  Producer();
  void run();
  void setBuffer(Buffer* buffer);

private:
  /// We are given an instance of the circular buffer we are to use when
  /// the Producer is created
  Buffer* buffer;

  /// We are given a handle to the Consumer we are working with so that we can
  /// resume them if we make the buffer non empty again
  Consumer* consumer;

  int producerPauseCount;
  int consumerResumeCount;
};

#endif // PRODUCER_HPP