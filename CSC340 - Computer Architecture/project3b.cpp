//Matt Meglan
//Project 1 CSC 340
//Bad c++ of square root

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
  double e = 0, y = 0, x = 0, c = 0;
  cout << "Tolerance please: ";
  cin >> e;
  
  topofloop:
  if (y >= 0)
  {
    if(y < 0)
      goto breakloop;
    cout << "Real number please (negative to end): ";
    cin >> y;
    if (y<0)
      goto breakloop;
    cout << endl;
    x = y / 2;
    c = (x*x) - y;
    topofloop2:
    if(abs(c) > e)
      {
      if(abs(c) <= e)
        goto breakloop;
      x = x - (c/(2 * x));
      c = (x*x) - y;
      goto topofloop2;
      }
  cout << "Square root of x is " << x << endl;
  goto topofloop;     
  }
breakloop:  
return 0;
}