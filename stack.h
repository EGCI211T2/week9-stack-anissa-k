
#ifndef stack_h
#define stack_h
#include "node.h"

class Stack {
	NodePtr top;
	int size;
public:
    void push(int);
    int pop();
    Stack();
    ~Stack();
    bool isEmpty();
};

void Stack::push(int x){
  NodePtr new_node=new NODE(x);
  size++;
  if( top == NULL)
  {
    top = new_node;
    return;
  }
  if(new_node){
    new_node->set_next(top);
    top = new_node;
   }
}

int Stack::pop()
{
    if (!top) 
    {
        return 0;
    }
    size--;
    NodePtr t = top;
    top = t->get_next();
    int value = t->get_value();
    delete t;
    return value;
}

Stack::Stack()
{
    //initialize stack
    size = 0;
    top = NULL;
}
Stack::~Stack()
{
    while (top) 
    {
        pop();
    }
}

bool Stack::isEmpty()
{
    return size==0;
}


#endif
