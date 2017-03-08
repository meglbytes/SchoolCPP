//Matthew Meglan
//CSC 310 Project 2 Slow
//Simple search type that is tested for time complexity 

#include <iostream>
#include <fstream>
using namespace std;

void bubble (int a[], int N)
  {
  int i, j, temp; 
  for (i = N; i >= 1; i--)
    for (j = 1; j <= i; j++)
      if (a[j-1] > a[j]) 
        {
        temp = a[j-1];
        a[j-1] = a[j];
        a[j] = temp;
        }     
  }

int numbers[1000000];

int main ()
{
  int n=0;
  int m=0;
  int x=0;
  int i=0;
  
  while (cin >> n)
    {
    numbers[m]=n;
    m++;
    i++;
    }  
  bubble (numbers,i);
  
  while (x<i)
    {
    cout << numbers[x] << endl;
    x++;
    }


  return 0;
}


