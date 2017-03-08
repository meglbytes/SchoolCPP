//Matt Meglan
//Project 1 CSC 340
//Good c++ of square root

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
  double e = 0, y = 0, x = 0, c = 0;
  cout << "Tolerance please: ";
  cin >> e;
  while (y >= 0)
  {
    cout << "Real number please (negative to end): ";
    cin >> y;
    if (y<0){
      break;}
    cout << endl;
    x = y / 2;
    c = (x*x) - y;
    while (abs(c) > e)
      {
      x = x - (c/(2 * x));
      c = (x*x) - y;
      }
      cout << "Square root of x is " << x << endl; 
  }
return 0;
}