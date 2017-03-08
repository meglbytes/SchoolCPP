//Matt Meglan
//Project 4 Sotware Systems
//11/4/12
//This program converts decimal integers to an arbitary base

#include <iostream>

using namespace std;

int main(argc, *argv[])
{

  cout << "There are " << argc << " arguments" << endl;
  
  cout << "They are ...\n";
  
  for (int i=1; i<argc; ++i)
    cout << "arg number " << i << " is '" << argv[i] << "'\n"; 
  


return 0;
}
