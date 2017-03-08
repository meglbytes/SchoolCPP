//Slow file by Matt Meglan

#include <iostream>

using namespace std;

int main ()
{
  for (int x = 0; x < 100; x++)
  {  
    cout << "Slow number: " << x << endl;
        
    for (int y = 0; y < 1000000000; y++)
    {
    }
  } 
}
