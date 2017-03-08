//Matt Meglan
//CSC 330 Project 4
//Counts the number of ocurrences of a particaular characters wtihin all files in a specified directory using threads

#include <iostream>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <unistd.h>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

using namespace std;

int sum = 0; 
int round = 0;
int tcount = 0;
char charpass;

void* threadfunc(void* voidfile)
{
  pthread_mutex_t al = PTHREAD_MUTEX_INITIALIZER;  
  int threadc = 0;  
  char b;
  int charcounter = 0;
  ifstream infile;
  char* myfile = (char*)voidfile;
  int roundx = 0;

  while (true)
    {
    if (round == roundx+1)
      {
      if (charpass == '\0')
        {
        cout << "Cyaaaa " << endl;
        break;
        }
      else
        {
        infile.open(myfile);
        charcounter = 0;
        while (infile.get(b))
          {
          if (b == charpass)
             charcounter++;
          }
          infile.close();
          roundx++;
          pthread_mutex_lock(&al);
          sum = sum + charcounter;
          tcount++;
          pthread_mutex_unlock(&al); 
        }
      }
    } 
}

int main (int argc, char *argv[])
{
  DIR *directorystr;
  directorystr = opendir (argv[1]);    //opens current directory
  chdir (argv[1]);
  dirent *cfile;
  tcount = 0;
  pthread_t t1[1000];
  int x = 0;  

  while (true)
    {
    cfile = readdir(directorystr); //current file from specified directory 
    if (cfile == NULL)
      break;
    if ((cfile -> d_type & DT_REG) != 0) //only looking at regular files
      {
      pthread_create(&t1[x], NULL, threadfunc, (void*)cfile -> d_name);
      x++;
      //cout << "Thread created for..." << cfile -> d_name << endl;
      }   
    }                    
   
  while (true)
    {
    sum = 0;
    cout << "Enter a character to search for: ";
    cin >> charpass;
    if (charpass == 'Q')
      {
      charpass = '\0';
      round++;
      }
    else
      {
      tcount = 0;
      round++;
      }
    if (charpass == '\0')
      break;
    while (tcount != x)
      {
       
      ;
      }
      cout << endl << "Files in this directory contain a total of " << sum << " '" << charpass << "' characters." << endl; 
    }
  
  for (int n = 0; n < x; n++)
    pthread_join(t1[n], NULL);

return 0;
}


