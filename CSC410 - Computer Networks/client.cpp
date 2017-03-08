//Matt Meglan
//CSC-410 Project 4
//Simple client programt to run with a server program

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

void process(int sock_descript)
{
  unsigned char code = 90;
  int charc;
  write(sock_descript, &code, 1);
  read(sock_descript, &charc, 4); 
  cout << "Server PID is: " << ntohl(charc) << endl;
}

void file_size(int sock_descript)
{
  unsigned char code = 91;
  char file_name[200];
  int charc;
  cout << "Name of file please: ";
  cin >> file_name;
  unsigned char size = strlen(file_name);
  write(sock_descript, &code, 1);
  write(sock_descript, &size, 1);
  write(sock_descript, &file_name, strlen(file_name));
  read(sock_descript, &charc, sizeof(charc)); 
  if (charc == -1)
    cout << "File not found" << endl;
  else
    cout << "File size is: " << ntohl(charc) << " bytes long" << endl;
}


void put_line(int sock_descript)
{
  unsigned char code = 92;
  char message[200], c;
  int charc, i=0;
  cout << "Line of text to send: ";
  while (true)
  {
    cin.get(c);
    if (c == '\n')
      break;
    message[i] = c;
    i++;
  }
  message[i]='\0';                  
  unsigned char size = strlen(message);
  write(sock_descript, &code, 1);
  write(sock_descript, &size, 1);
  write(sock_descript, &message, i);

}

void system_info(int sock_descript)
{
  unsigned char code = 93;
  char o, m;
  int i, q; 
  char os_release[200], machine_type[200];
  write(sock_descript, &code, 1);
  read(sock_descript, &o, 1);
  i = o;
  read(sock_descript, &os_release, i);
  read(sock_descript, &m, 1);
  q = m;
  read(sock_descript, &machine_type, m);
  cout << "OS Release number: ";
  for (int t=0; t < i; t++)
    cout << os_release[t];
  cout << endl;
  cout << "Machine type: ";
  for (int z=0; z < q; z++)
    cout << machine_type[z];
}

int main (int argc, char *argv[])
{
  cout<<endl;
  unsigned long int ipaddr;
  int num;
  char p;
  //creating structer iparddr of type hostent from function gethostbyname
  struct hostent * netinfo = gethostbyname(argv[1]);
  //going into structure netinfo and copying to variable
  if (netinfo == NULL)
    cout << "Host not found dude.";
  else
    bcopy(netinfo -> h_addr,&ipaddr,4);
  //cout << ipaddr << endl;
  
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
  num = connect(socknbr, (struct sockaddr*)&insock, sizeof(insock));

  if (num = 0)
  {
    cout << "*** Connection Failed ***" << endl;
    return 0;
  }
  else
    cout << "*** Connection Established ***" << endl;

  //Menu
  int entry = 0;
  while (entry != 5)
  {
    cout << "1. PID" << endl;
    cout << "2. File Size" << endl;
    cout << "3. Put Line" << endl;
    cout << "4. System Info" << endl;
    cout << "5. Exit" << endl;
    cout << "Please enter a menu selection: ";
    cin >> entry;
    cin.get(p);
    cout << endl;
    if (entry == 1)
      process(socknbr);
    else if (entry == 2)
      file_size(socknbr);
    else if (entry == 3)
      put_line(socknbr);
    else if (entry == 4)
      system_info(socknbr);
    cout << endl;
    }


  
return 0;
}
