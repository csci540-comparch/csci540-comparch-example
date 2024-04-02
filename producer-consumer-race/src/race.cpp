/**
 * @file race.cpp
 * @brief Example of fatal race condition
 *
 * Example of a fatal race condition using a producer/consumer
 * manipulation of a shared buffer.  Example from Tanenbaum
 * "Structure Computer Organization (2012)" chapter 6
 * Figure 6-26.  Race condition present because we use
 * pause/resume where a signal can be lost because of
 * non atomic nature of tests to pause/resume the
 * producer and consumer threads.
 */
#include "Buffer.hpp"
#include "Consumer.hpp"
#include "Producer.hpp"
#include "prime.hpp"
#include <iostream>

using namespace std;

/**
 * @brief main entry point
 *
 * Main entry point for our race condition example program.  We define but
 * do not use input arguments and we always return 0 on successfuly exit.
 *
 * @param argc The argument count (unused)
 * @param argv The command line argument (string) values (unused)
 *
 * @returns int Always returns 0 on successful completion of this program.
 */
int main(int argc, char** argv)
{
  /*
  bigint prime = 1;
  while (prime != MAX_PRIME)
  {
    prime = nextPrime(prime);
    cout << prime << " " << flush;
  }
  */

  // create a buffer, consumer and producer
  Buffer* buffer = new Buffer();
  Consumer* consumer = new Consumer();
  Producer* producer = new Producer();

  // provide references/pointers to consumer and producer to do their work
  consumer->setBuffer(buffer);
  consumer->setProducer(producer);
  producer->setBuffer(buffer);
  producer->setConsumer(consumer);

  thread pthread([&]() { producer->run(); });
  thread cthread([&]() { consumer->run(); });

  pthread.join();
  cthread.join();

  // return exit code 0 on successful completion
  return 0;
}