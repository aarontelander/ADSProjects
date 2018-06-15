#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include "elapsed_time.h"

using namespace std;

struct node {
  int info;
  node * next;
};
node * top = NULL, * bot = NULL, * cur = NULL, * np = NULL;

void push(int x) {
  np = new node;
  np->info = x;
  np->next = NULL;
  if (bot == NULL) {
    top = np;
    bot = top;
    top->next = NULL;
  }
  else {
    top->next = np;
    top = np;
    top->next = NULL;
  }
}

int pop() {
  int x;
  if (top == NULL) {
    cout << "YOU SUCK!!!" << endl;
    return -1;
  }
  else {
    cur = top;
    x = cur->info;
    top = top->next;
    delete(cur);
    return x;
  }
}

int main() {
  int testnum = 1000000;
  start_timer();
  for (int i=0; i<testnum; i++)
    push(i);
  cout << elapsed_time() << endl;
  /*push(5);
  cout << "Cycles for push: " << elapsed_time() << endl;
  cout << pop() << endl;
  cout << "Cycles for cout and pop: " << elapsed_time() << endl;*/
  return 0;
}
