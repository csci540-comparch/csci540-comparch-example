/**
 * @file exec.c
 * @brief Linux process management system calls
 *
 * Example of fork() and exec() combination.  fork()
 * creates a new process, but both parent and new child
 * run same code segment.  The exec() causes a new code
 * segment to be loaded and executed.
 *
 * Examples from Richard (2013) "Advanced Programming in the UNIX Environment" 3ed
 */
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char** argv)
{
  pid_t pid;

  printf("before fork\n");

  // fork returns 2 times, once in original process, and once in a newly created process
  pid = fork();

  // in the new child process, the same code is running but a 0 is returned
  // as result from fork
  if (pid == 0) // pid was 0 so we are the child
  {
    printf("child process running\n");
    printf("child pid: %d\n", getpid());

    char* env_init[] = {"USER=unknown", "PATH=/tmp", NULL };
    printf("child process will now exec() and run new code\n");
    execle("./echoall", "echoall", "myarg1", "MY ARG2", (char*) 0, env_init);
  }
  // in the original parent process, we are running same code, but the pid of
  // the newly created child is returned from the fork
  else // pid was not 0 so we are the parent
  {
    int status;
    
    printf("parent process running, child pid: %d\n", pid);
    printf("parent pid: %d\n", getpid());
    printf("parent waiting on child to exit\n");
    
    // wait for (a) child to exit and get status of exiting child
    wait(&status);
    printf("parent detectes child has exited with status: %d\n", WEXITSTATUS(status));

    // the parent also returns an exit status code back to bash shell we run this from
    exit(22);
  }
  
}
