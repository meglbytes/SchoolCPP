//Matthew Meglan
//CSC 330 Project 3
//Counts the number of cocurrences of a particaular characters wtihin all files in a specified directory

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
using namespace std;

int main (int argc, char *argv[])
{
  DIR *directorystr;
  directorystr = opendir (argv[1]);    //opens current directory
  dirent *cfile;
  int pid, pip[2], pipeary[1000][2], ccount = 0;
  char charpass;
  ifstream infile;
  int charcounter, tcount;
  char b; 
  
  pipe(pip); //pip for children to write too
  
  
  while (true)
    {
    cfile = readdir(directorystr); //current file from specified directory 
    if (cfile == NULL)
      break;
    if ((cfile -> d_type & DT_REG) != 0) //only looking at regular files
      {
    
      pipe(pipeary[ccount]); //creates pipe for children
      pid = fork();
      if (pid == 0)
        {
        //cout << getpid()<< " ";
        //cout << cfile -> d_name << endl;
        while (true)
          {
          read(pipeary[ccount][0], &charpass, sizeof(charpass));
          if (charpass == '\0')
            {
            cout << "Cyaaaa " << getpid() << endl;
            exit(0);
            }
          else
            {
            //cout << " You searched for: " << charpass << endl;
            infile.open(cfile -> d_name);
            charcounter = 0;
            
            while (infile.get(b))
              {
              if (b == charpass)
                charcounter++;
              }
            infile.close();
            //cout << getpid() << " " << charcounter;
            write(pip[1], &charcounter, sizeof(charcounter)); 
            }
            
          }
        }
        else
          ccount++;                      
      }
    }
    
  while (true)
    {
    cout << "Enter a character to search for: ";
    cin >> charpass;
    if (charpass == 'Q')
      {
      charpass = '\0';
      }
      for (int i=0; i < ccount; i++)
        write(pipeary[i][1], &charpass, sizeof(charpass));
      if (charpass == '\0')
        break;
      
      tcount = 0;
      int n;
        
      for (n = 0; n < ccount; n++)
        {
        read(pip[0], &charcounter, sizeof(charcounter));
        tcount = tcount + charcounter;  
        }
      cout << "Files in this directory contain a total of " << tcount << " '" << charpass << "' characters." << endl;
       
    }
return 0;
}