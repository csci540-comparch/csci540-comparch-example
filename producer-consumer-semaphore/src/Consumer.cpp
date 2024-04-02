#include "Consumer.hpp"

using namespace std;

Consumer::Consumer()
{
  this->buffer = nullptr;
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
    buffer->filled.release();
    emirp = buffer->buffer[buffer->out];                       // statement C2 (consume next prime)
    buffer->out = buffer->next(buffer->out);                   // statement C3 (increment circular buffer next out)
    buffer->available.acquire();
    cout << (emirp) << " " << flush; // statement C5 (display item consumed)
  }
}

void Consumer::setBuffer(Buffer* buffer)
{
  this->buffer = buffer;
}
