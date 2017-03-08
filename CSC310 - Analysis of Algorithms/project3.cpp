//Matt Meglan
//CSC 310 Project 3
//Implements Horner's method of computing modulo

#include <iostream>
#include <cstdlib>
using namespace std;

int main (int argc, char *argv[])
{
int div=atoi(argv[2]);
int quo=0;
int i=0;
  
for(i=0;argv[1][i]!='\0';i++)                          
  quo=(quo*256+argv[1][i])%div;
    
cout<<"Output: "<<quo<<"\n";

return 0;
}
