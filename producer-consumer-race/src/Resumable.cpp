#include "Resumable.hpp"

Resumable::Resumable()
{
  pauseSignal = promise<void>();
  futureObj = future<void>(pauseSignal.get_future());
  pauseSignal.set_value();
}

void Resumable::operator()()
{
  run();
}

/**
 * Pause works by creating a promise.  The status of the promise
 * is used as a signal.
 */
void Resumable::pause()
{
  pauseSignal = promise<void>();
  futureObj = future<void>(pauseSignal.get_future());
}

/**
 * Resume gets the status of the promise used as a signal.  When
 * the promise/signal is ready we resume the thread execution.
 */
void Resumable::resume()
{
  auto status = futureObj.wait_for(chrono::milliseconds{0});
  if (status != future_status::ready)
  {
    pauseSignal.set_value();
  }
}

/**
 * This method is called in the thread run() task in main loop, it will
 * not return when thread is paused, and will finally return once thread
 * is resumed.
 */
void Resumable::waitForResume()
{
  futureObj.wait();
}
