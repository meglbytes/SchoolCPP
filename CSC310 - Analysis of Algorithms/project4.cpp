//Matt Meglan
//CSC-310 Project 4
//Building a hash table from input records

#include <iostream>
#include <cstdlib>
#include <string.h>
using namespace std;

struct personal_accounts
{
  int userid;
  char log[8];
  char name[21];
  char stat;
};

int mod (int t, char a[])
{
  int x;
  int result = 0;
  for (x = 0; a[x] != '\0';x++)
    result = (result * 256 + a[x]) % t;
  return result;
}

int hash (char key[], int m)
{ 
  return mod (m, key);
}

int doublehash (char key[])
{
  return 7 - mod (7, key);
}

bool primefunc (unsigned long p)
{
  unsigned long d;
  
  if (p >= 2)
    {
      for (d = 2; d* d <= p; ++d)
        if (p % d == 0)
          return false;
        return true;
    }
    else
      return false;
}  

int main (int argc, char *argv[])
{
  int nom = atoi (argv[1]);
  long int x;
  char log[9], name[21], command;
  int i, hashmod, prime, hashmod2, userid;
  
  for (x = nom; !primefunc (x); ++x);
  cout << endl << "Smallest prime greater than or equal to " << nom << " is " << x << endl;

  personal_accounts *htable = new personal_accounts [x];
  personal_accounts *place;
  for (i = 0; i < x; i++)
    {
      place = &htable[i];
      place -> stat = 'e';
    }
  while (true)
    {
      cout << "Press 'a' to add a record. 'd' to delete. look up press 'l'. 'q' to quit." << endl;
      cin >> command;
      if (command == 'a' || command == 'l' || command == 'd')
        {
          cout << "LOGIN: ";
          cin >> log;
          hashmod = hash ((char *) log, x);
          hashmod2 = doublehash ((char *) log);
          place = &htable[hashmod];
        }

      if (command == 'a')
        {
        cout << "ID number please: ";
        cin >> userid;
        cout << "Name please: ";
        cin.get ();
        cin.get (name, 20);
        
        while (true)
          {
          place = &htable[hashmod];
          if (strcmp (place -> log, log) == 0)
            {
              cout << "Copy found" << endl;
              break;
            }
          else if (place -> stat == 'd' || place -> stat == 'e')
            {
              strcpy (place -> log, log);
              strcpy (place -> name, name);
              place -> userid = userid;
              place -> stat = 'f';
              break;
            }
          else
            {
              hashmod = (hashmod + hashmod2) % x;
            }
          }
        }
     else if (command == 'd')
       {
         while (true)
           {
             place = &htable[hashmod];
             if (place -> stat == 'e')
               {
                 cout <<
                 cout << "not found in table!" << endl;
                 break;
               }

             else if (strcmp (place -> log, log) == 0)
               {  
                 place -> stat = 'd';
                 break; 
               }
             else
               {
                 hashmod = (hashmod + hashmod2) % x;
               }
            }
        }
      else if (command = 'l')
        {
          int counter = 1;
          while (true)
            {
              place = &htable[hashmod];
              if (place -> stat == 'e' || place -> stat == 'd')
                {
                  cout << endl;
                  cout << "Not found in table!" << endl;
                  cout << "searched " << counter << " buckets" << endl;
                  break;
                }
              else if (strcmp (place -> log, log) == 0)
                {
                  cout << place -> log << endl;
                  cout << place -> userid << endl;
                  cout << place -> name << endl;
                  break;
                }
              else
                {
                  counter++;
                  hashmod = (hashmod + hashmod2) % x;
                } 
              }
          }
       else if (command == 'q')
         {
           break;
         }
       }
return 0;
}

