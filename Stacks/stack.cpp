#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include "elapsed_time.h"

using namespace std;

class Stack
{
  int * elements;
  int sp;   // Stack Pointer
  int length;
public:
  Stack(int);
  void stack_extend();
  void push(int);
  int pop();
  void stack_status();
};

Stack::Stack (int size) {
  elements = new int[size];
  sp = -1;
  length = size;
}

void Stack::stack_extend() {
  if (sp == length-1) {
    int * temp = new int[length+100];
    for (int i=0; i<length; i++)
      temp[i] = elements[i];
    delete elements;
    elements = temp;
    delete temp;
    length += 100;
  }
}

void Stack::push(int n) {
  stack_extend();
  sp++;
  elements[sp] = n;
}

int Stack::pop() {
  stack_extend();
  sp--;
  return elements[sp+1];
}

void Stack::stack_status() {
  cout << "pointer: " << sp << endl;
  cout << "top: " << elements[sp] << endl;
  cout << "size: " << length << endl;
}

int main() {
  int testnum = 1000000;
  Stack mystack(testnum);
  start_timer();
  for (int i = 0; i<testnum; i++)
    mystack.push(i);
  cout << elapsed_time() << endl;
  /*
  mystack.push(1);
  mystack.push(2);
  cout << "Cycles for two pushes: " << elapsed_time() << endl;
  mystack.pop();
  cout << "Cycles for cout and pop: " << elapsed_time() << endl;
  */
  /* Stack mystack(5);
  mystack.stack_status();
  mystack.push(1);
  mystack.stack_status();
  mystack.push(2);
  cout << "This should be a two " << mystack.pop() << endl;
  mystack.push(2);
  mystack.push(3);
  mystack.push(4);
  mystack.push(5);
  cout << "This should be a five " << mystack.pop() << endl;
  cout << "This should be a four " << mystack.pop() << endl;
  mystack.push(6);
  mystack.push(7);
  mystack.stack_status(); */
  return 0;
}
