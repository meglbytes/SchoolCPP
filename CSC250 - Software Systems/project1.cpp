//Matt Meglan
//CSC 250 Project 1
//This program runs an ifinite loop waiting for user to imput number returning the square and square root of that number until '0' is entered 

#include <iostream>
#include <cmath>

using namespace std;

int main ()
{
  int x;
  
  cout << "\nHello. This is M Squuurred\n";
  
  while (true)
  {
    if (x != 0)
    {
      cout << "\nEnter a number: ";
      cin >> x;
      cout << x << " squared is " << x*x << "." << " The square root of " << x << " is " << sqrt(x);
      cout << endl;
    }
    
    else
    {
      cout << "\nGoodbye!\n";
      break;
    }
  }
  
  
    
return 0;
}