#include "Consumer.hpp"

using namespace std;

Consumer::Consumer()
{
  this->buffer = nullptr;
  this->producer = nullptr;
  consumerPauseCount = 0;
  producerResumeCount = 0;
}

/**
 * Implement run() method that is run in a thread.  Repeatedly take
 * item next biggest prime out of the circular buffer and display it
 * to cout.  If the buffer is empty, we pause() ourself waiting for the
 * producer to add an item and resume() us.
 */
void Consumer::run()
{
  bigint emirp;
  cout << "Consumer::run() entered" << endl;

  while (emirp < MAX_PRIME)
  {
    if (buffer->in == buffer->out) // statement C1 (buffer empty)
    {
      consumerPauseCount++;
      cout << "Consumer pausing count: " << consumerPauseCount << endl;
      pause();
    }
    emirp = buffer->buffer[buffer->out];                       // statement C2 (consume next prime)
    buffer->out = buffer->next(buffer->out);                   // statement C3 (increment circular buffer next out)
    if (buffer->out == buffer->next(buffer->next(buffer->in))) // statement C4 (buffer was full
    {
      producerResumeCount++;
      cout << "Producer resume count: " << producerResumeCount << endl;
      producer->resume();
    }
    // cout << (emirp) << " " << flush; // statement C5 (display item consumed)
  }
}

void Consumer::setBuffer(Buffer* buffer)
{
  this->buffer = buffer;
}

void Consumer::setProducer(Producer* producer)
{
  this->producer = producer;
}
