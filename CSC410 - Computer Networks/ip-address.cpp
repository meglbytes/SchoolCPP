//Matt Meglan
//CSC 410 Project 1
//Returns IP address of personal, network and internet IP addresses

#include <iostream>
#include <netdb.h>
#include <string>
#include <arpa/inet.h>
#include <netinet/in.h>
using namespace std;


int main ()
{
  string hname;
  char realname[500]; 
  
  while (true)
  {
    cout << "Host name: ";
    cin >> hname;
    
    if (hname=="STOP" || hname=="Stop" || hname=="stop")   
      break;
    else
    {
      int temp=hname.size();
      for (int i=0; i<=temp; i++)
        realname[i]=hname[i]; 
                
      hostent * compinfo = gethostbyname(realname);
      
      if (compinfo == NULL)
        cout << "Host not found!" << endl;
        
      else
        {
        string hostname = compinfo->h_name; 
        cout << "Official name: " << hostname << endl;
        in_addr * address=(in_addr * )compinfo->h_addr;
        unsigned int longip = inet_addr(inet_ntoa(* address));
        cout << "IP address: " << inet_ntoa(* address) << " (" << longip << ")" << endl;
        cout << endl;
        }
    } 
  }
  
 cout << "buh bye" << endl;
  
  return 0;
}    
