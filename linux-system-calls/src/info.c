/**
 * @file info.c
 * @brief Linux system information calls
 *
 * Example of some basic but important system information calls.
 *
 * Examples from Richard (2013) "Advanced Programming in the UNIX Environment" 3ed
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/utsname.h>

int main(int argc, char** argv)
{
  // each process is assigned a unique process identifier pid when it is forked
  pid_t mypid;
  mypid = getpid();
  printf("My process identifier pid: %d\n", mypid);

  // all processes are forked from a single parent, a parent may have may children, by
  // all processes have a single parent
  pid_t myppid;
  myppid = getppid();
  printf("My parent process identifier ppid: %d\n", myppid);

  // all resources (files, processes, etc.) are owned by and associated with a user, the userid
  // for this process is the user defined by the OS that created and owns this process
  uid_t myuid;
  myuid = getuid();
  printf("My user identifier uid: %d\n", myuid);

  // groups are defined that users can belong to, all resources also have a group that owns them
  gid_t mygid;
  mygid = getgid();
  printf("My group identifier gid: %d\n", mygid);

  // some miscellaneous system information calls, uname returns information about host and OS
  struct utsname sysinfo;
  uname(&sysinfo);
  printf("Operating system name: <%s>\n", sysinfo.sysname);
  printf("Node name            : <%s>\n", sysinfo.nodename);
  printf("OS release           : <%s>\n", sysinfo.release);
  printf("OS version           : <%s>\n", sysinfo.version);
  printf("Machine hardware     : <%s>\n", sysinfo.machine);
  
  exit(0);
}
