//Matthew Meglan
//CSC 330 Project 2
//Creates child processes by using fork system call

#include <iostream>
#include <unistd.h>
#include <stdlib.h>
using namespace std;

int main ()
{ 
  int n;  
  cout<<"How many processes would you like? (1-26) ";
  cin>>n;
  if (n>26||n<1)
    {
    cout<<"Hey man its gotta be between 1 and 26 like I said earlier."<<endl;
    exit(0);
    }
  char name;
  name='A';

  for(int i=1;i<=n;i++)
    {
    int value = fork();
      if (value==0)
	{
    	cout<<"This is the child process "<<name<<" ";
        cout<<getpid()<<endl;
	exit(0);
        }
     name++;
    }

return 0;
}
