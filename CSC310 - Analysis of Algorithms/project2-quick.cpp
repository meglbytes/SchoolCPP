//Matthew Meglan
//CSC 310 Project 2 Quick
//Iterative Quick Sort Algorithm

#include <iostream>
#include <fstream>
using namespace std;

int numbers[1000000];

int median (int a, int b, int c)
  {
  if ((a<=b && b<=c) || (c<=b && b<=a))
    return b;
  else if ((a<=c && c<=b) || (b<=c && c<=a))
    return c;
  else 
    return a; 
   }
    
int partition(int A[],int l,int r)
  {
    int v;
    int i=l;
    int j=r;
    int temp;
    v = median( A[l], A[r], A[(l+r)/2]);
    while (i<j)
      {
      while (A[i]<v)
        i++;
      while (A[j]>v)
        j--;
      temp=A[i];
      A[i]=A[j];
      A[j]=temp;
      }  
    return i;
  }

int qs(int A[], int l, int r)
  {
  int stack[100];
  int sp=0;
  int i;
  while (true)
    {
    while (l<r)
      {
      i=partition(A,l,r);
      if((i-l)>(r-i))
        {
        stack[sp]=l;
        sp++;
        stack[sp]=(i-1);
        sp++;       
        l=i+1;
        }
      else
        {
        stack[sp]=(i+1);
        sp++;
        stack[sp]=r;
        sp++;
        r=i-1;
        }
      }
    if(sp==0)
      break;
    else
      {
      r=stack[--sp];
      l=stack[--sp];
      }
    }  
  }


/*int qs(int A[], int l, int r)
  {
  if (l<r)
    {
    int i=partition(A,l,r);
    qs(A,l,i-1);
    qs(A,i+1,r);
    }
  }
*/

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
  qs (numbers, 0, m-1);
  
  while (x<i)
    {
    cout << numbers[x] << endl;
    x++;
    }
       
  return 0;
  }