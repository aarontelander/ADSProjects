#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

const int num_nodes = 5;

void print_graph(vector<vector<int>> graph){
  for(int i=0; i<num_nodes; ++i){
    for(int j=0; j<num_nodes; ++j){
      cout << graph[i][j] << '\t';
    }
    cout << endl;
  }
}
void init_graph(vector<vector<int>> &graph){
  graph[0][2] = -2;
  graph[1][0] = 4;
  graph[1][2] = 3;
  graph[2][3] = 2;
  graph[3][1] = -1;
}

void init_graph2(vector<vector<int>> &graph){
  graph[0][1] = 3;
  graph[0][2] = 3;
  graph[1][4] = 2;
  graph[2][3] = 1;
  graph[3][1] = -3;
  graph[4][0] = 4;
}

void fw(vector<vector<int>> &graph) {
  //Got the algorithm from https://www.youtube.com/watch?v=4OQeCuLYj-4
  for(int k=0; k < num_nodes; ++k){
    for(int i=0; i < num_nodes; ++i){
      for(int j=0; j < num_nodes; ++j){
        if(graph[i][j] > graph[i][k] + graph[k][j]){
          graph[i][j] = graph[i][k] + graph[k][j];
        }
      }
    }
  }
}

int main() {
  vector<vector<int>> graph;
  for(int i=0; i<num_nodes; ++i){
    vector<int> tmp;
    graph.push_back(tmp);
  }
  for(int i=0; i<num_nodes; ++i){
    for(int j=0; j<num_nodes; ++j){
      if(i==j){
        graph[i].push_back(0);
      }
      else{
        graph[i].push_back(999);
      }
    }
  }

  //init_graph(graph);
  init_graph2(graph);
  cout << "INTIAL STATE:" << endl;
  print_graph(graph);
  cout << endl;
  cout << "FINAL STATE:" << endl;
  fw(graph);
  print_graph(graph);

  return 0;
}
