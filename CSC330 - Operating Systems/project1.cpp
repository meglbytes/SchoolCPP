//Matthew Meglan
//CSC 330 Project 1
//System Calls

#include <iostream>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>
#include <netdb.h>
using namespace std;

int main ()
{ 
  char hostname[300];
  timeval time; 
  
  cout << getppid() << endl;
  
  sleep (3);

  gethostname(hostname, sizeof hostname); 
  
  cout << hostname << endl;
  
  cout << getuid() << endl;
  
  gettimeofday(&time, NULL);
  
  cout << ctime(&time.tv_sec) << endl;    
         
return 0;
}