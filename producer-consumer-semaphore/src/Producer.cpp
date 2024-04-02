#include "Producer.hpp"

Producer::Producer()
{
  this->buffer = nullptr;

  producerPauseCount = 0;
  consumerResumeCount = 0;
}

/**
 * Implement run() method that is run in a thread.  Repeatedly generate
 * the next biggest prime and add it to the circular buffer.  If the
 * buffer becomes full, we pause() ourself waiting for the consumer to
 * take an item and resume() us.
 */
void Producer::run()
{
  bigint prime = 1;

  cout << "Producer::run() entered" << endl;

  while (prime < MAX_PRIME)
  {
    prime = nextPrime(prime);                    // statement P1 (generate next prime)
    buffer->available.release();
    buffer->buffer[buffer->in] = prime;          // statement P3 (produce next prime)
    buffer->in = buffer->next(buffer->in);       // statement P4 (increment circular buffer next in)
    buffer->filled.acquire();
  }
}

void Producer::setBuffer(Buffer* buffer)
{
  this->buffer = buffer;
}
