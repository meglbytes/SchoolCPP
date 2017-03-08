//Matthew Meglan   
//CSC 310 Project 1
//Binary tree created from integer input file.  User can search and see path to values.

#include <iostream>
#include <fstream>
using namespace std;
struct node
  {
  int value;
  node *left;
  node *right;
  };
                
node *root = NULL;
node *tmp_ptr = NULL;
node *new_ptr = NULL;

/*
void in_order (struct node* root)
	{
	if (root != NULL)
		{
		in_order(root -> left);
		cout << (root -> value) << endl;
		in_order (root -> right);
	        }
	}
*/

int main (int argc, char* argv[])
  {
  int i;                    
  ifstream myfile;
  cout << "Reading from the file " << "'" << argv[1] << "'" << "..." << endl;
  myfile.open(argv[1]);
  while (myfile >> i)
  {
  new_ptr = new node;
  new_ptr -> value = i;
  new_ptr -> left = NULL;
  new_ptr -> right = NULL;
                                  
    //tree construction
    if (root == NULL) //first value goes at head
      root = new_ptr;
    else //susequent values go in binary tree 
      {
      tmp_ptr = root;
      while (true)
        {   
        if (new_ptr -> value <= tmp_ptr -> value) //travels left
	  {
	  if (tmp_ptr -> left == NULL)
	   {
           tmp_ptr -> left = new_ptr;
	   break;
	   }
	  else	
           tmp_ptr = tmp_ptr -> left;
	  }
        else //travels right
	  {
          if (tmp_ptr -> right == NULL)
	    {
	    tmp_ptr -> right = new_ptr;
	    break;
	    }
	  else
	   tmp_ptr = tmp_ptr -> right;
	  }        
        }
      }       
  }

//in_order (root);


  //user searches list 
  while (true)
    {
    cout << "Enter a number: ";
    int c;
    cin >>  c;
    if (c<0)
      {
      cout<<"free at last free at last!"<<endl;
      break;
      }
    tmp_ptr = root;
    cout << "Search path: ";  
    while (true)
      { 
        if (c < tmp_ptr -> value) //travels left
	  {
	  if (tmp_ptr -> left == NULL)
	   {
           cout << "... not found" << endl;
	   break;
	   }
	  else
	   {	
           tmp_ptr = tmp_ptr -> left;
	   cout << "L";
	   }
	  }
        else if (c > tmp_ptr -> value) //travels right
	  {
          if (tmp_ptr -> right == NULL)
	    {
	    cout << "... not found" << endl;
	    break;
	    }
	  else
	    {
	    tmp_ptr = tmp_ptr -> right;
	    cout << "R";
	    }
	  }        
	else
	  { 
	  cout << "... found it" << endl;
	  break;
	  }
        }
      }
                                                                                                                                                                                                                                                                                                                                                                                
return 0;
}
                                                                                                                                                                                                                                                                                                                                                                             
