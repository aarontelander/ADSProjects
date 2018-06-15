#include <iostream>
#include <stack>
#include "elapsed_time.h"

using namespace std;

int main() {
  std::stack<int> mystack;
  int testnum = 1000000;
  start_timer();
  for (int i=0; i<testnum; i++)
    mystack.push(i);
  cout << elapsed_time() << endl;
  /*mystack.push(5);
  cout << "Cycles for push: " << elapsed_time() << endl;
  mystack.pop();
  cout << "Cycles for pop: " << elapsed_time() << endl;*/
  return 0;
}
