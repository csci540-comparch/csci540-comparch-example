#ifndef RESUMABLE_HPP
#define RESUMABLE_HPP
#include <future>

using namespace std;

/**
 * @brief Base class to define a pause/resume thread function
 *
 * The basice c++ std::thread does not have pause/resume defined
 * natively.  As described in the text, this was being removed/
 * deprecated from Java Thread because it is unsafe, so this is
 * probably why c++ std never really had it.  But here we use
 * the following reference:
 *
 * to create a basic Resumable class that implements a pause and
 * resume function.  This uses a stl promise and future objects to
 * put thread into wait() which can be interrupted by sending
 * a resume signal (using the promise).
 */
class Resumable
{
public:
  Resumable();

  void operator()();
  void pause();
  void resume();
  void waitForResume();

  // This is an abstract base class, we must publically inherit from
  // and implement run() to use the Resumable definitions
  virtual void run() = 0;

private:
  promise<void> pauseSignal;
  future<void> futureObj;
};

#endif // RESUMABLE_HPP
