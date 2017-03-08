//Matt Meglan
//Project 1 CSC 340
//Bad C++ of computing exponentials

#include <iostream>

using namespace std;

int main()
{
  int base = 1, expo = 1, count = 0;
  
  if (base != 0)
  {
    topofloop:
    int result = 1;
    cout << "Enter a base: ";
    cin >> base;
    cout << endl;
    if (base == 0)
      goto outofloop;
    cout << "Enter an exponent: ";
    cin >> expo;
    cout << endl;
    int i = 0;
    expoloop:
    if (i = expo)
      {
      goto expobloop; 
      }
    result = result * base;
    i++;
    goto expoloop;
    expobloop:
    cout << base << "**" << expo << "=" << result << endl << endl;    
    count++;
    goto topofloop;
  }
  outofloop:
  cout << count << " exponentials have been computed. Toodles!\n";


return 0;
}
