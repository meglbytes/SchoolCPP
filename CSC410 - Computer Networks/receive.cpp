//Matt Meglan
//CSC 410 Project 3
//A receive program that supplies a port number for a simple send programs to communicate with

#include <iostream>
#include <netdb.h>
#include <string>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
using namespace std;

int main ()
{
  
  int socknbr;
  socknbr = socket(AF_INET, SOCK_STREAM, 0);
  if (socknbr == -1)
    cout << "Socket error";
  
while(true)
  {
  struct sockaddr_in sockaddress;
  sockaddress.sin_family = AF_INET;
  sockaddress.sin_port = INADDR_ANY;
  sockaddress.sin_addr.s_addr = INADDR_ANY;
  //use (sockaddr*) to trick compiler in thinking it that type
  bind(socknbr, (sockaddr*)&sockaddress, sizeof(sockaddress));

  socklen_t length;
  length = sizeof(sockaddress);
  int sname = getsockname(socknbr ,(sockaddr*)&sockaddress,&length);
  cout << ntohs(sockaddress.sin_port) << endl;

  listen(socknbr,1);

  int acceptfd;
  acceptfd = accept(socknbr,(sockaddr*)&sockaddress,&length);  
  
  char a;
  int r;
  do
    {
    r=read(acceptfd,&a,1);
    cout << a;
    }
  while(r!=0);
  }

 
return 0;
}
