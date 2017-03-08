//Matt Meglan
//CSC 410 Project 2
//A send program that outputs a message to a connected port over the internet

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

int main (int argc, char *argv[])
{
  unsigned long int ipaddr;
  //creating structer iparddr of type hostent from function gethostbyname
  struct hostent *netinfo = gethostbyname(argv[1]);
  //going into structure netinfo and copying to variable
  if (netinfo == NULL)
    cout << "Host not found dude.";
  else
    bcopy(netinfo -> h_addr,&ipaddr,4);
  cout << ipaddr << endl;
  
  //opening socket
  int socknbr;
  socknbr = socket(AF_INET, SOCK_STREAM, 0);
  if (socknbr == -1)
    cout << "Socket error";
      
  //asking and making the connection
  struct sockaddr_in insock;
  insock.sin_family = AF_INET;
  insock.sin_port = htons(atoi(argv[2]));
  insock.sin_addr.s_addr = ipaddr;
  //changes insock type from sockaddr in to sockaddr 
  connect(socknbr, (struct sockaddr*)&insock, sizeof(insock));

  char mssg;
  //cin.get for new lines and spaces
  //q means quit
  while (mssg!='q')
    {
    cin.get(mssg);
    write(socknbr, &mssg, 1);
    }
  
return 0;
}
