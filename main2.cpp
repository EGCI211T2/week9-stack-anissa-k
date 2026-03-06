#include<iostream>
#include<cstring>
using namespace std;

#include "stack.h"

int main(int argc, char **argv){
  for(int i=1; i<argc; i++)
  {
      Stack s;
      char t;
      int match=1;
    for(int j=0;j<strlen(argv[i]);j++){
        // Use stack to help with the parentheses
      switch(argv[i][j]){
        case '[':
        case '(':
        case '{': s.push(argv[i][j]); break;

        case '}': t=s.pop();
                  if(t!='{') match=0;
                  //check if they match
                  break;
        case ']': t=s.pop();
                  if(t!='[') match=0;
                  //chech if they match
                  break;
        case ')': t=s.pop();
                  if(t!='(') match=0;
                  //chech if they match
                  break;
      }
      if (match==0) break;

    }

    cout<< "argv" << " " << i << " ";
    if(match==0) 
    {
      cout<<"incorrect:mismatch"<<endl;
    }
    else if(!s.isEmpty()) 
    {
      cout <<"incorrect:too many open parentheses"<<endl;
    }
    else 
    {
      cout<<"correct"<<endl;
    }
  }
   return 0;
}
