//Matt Meglan
//Project 1 CSC 340
//Good C++ of ocmputing exponentials

#include <iostream>

using namespace std;

int main()
{
  int base = 1, expo = 1, count = 0;
  
  while (base !=0)
  {
    int result = 1;
    cout << "Enter a base: ";
    cin >> base;
    cout << endl;
    if (base == 0)
      break;
    cout << "Enter an exponent: ";
    cin >> expo;
    cout << endl;
    for (int i = 0; i<expo; i++)
      result = result * base;
    cout << base << "**" << expo << "=" << result << endl << endl;    
    count++;
  }

  cout << count << " exponentials have been computed. Toodles!\n";


return 0;
}
