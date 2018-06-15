#include <iostream>
#include <vector>
using namespace std;

class Vertex {
  int id;
  vector<int> connections;
  bool discovered;
public:
  Vertex(int,bool);
  vector<int> get_connections() {return connections;}
  void add_connection(int v) {connections.push_back(v);}
  bool is_discovered() {return discovered;}
  int get_id() {return id;}
  void make_discovered() {discovered=true;}
};

Vertex::Vertex(int n, bool b = false) {
  id = n;
  discovered = b;
}

int main() {
  // A-B takes 4
  // A-C takes 2
  // B-C takes 1
  // B-D takes 5
  // B-E takes 4
  // D-F takes 1
  // E-F takes 8
  // C-F takes 10
  // Best path: A-C-B-D-F (total: 9)

  /*
  Vertex A(0,true);
  Vertex B(1);
  Vertex C(2);
  Vertex D(3);
  Vertex E(4);
  Vertex F(5);
  */

  int numnodes = 6;

  vector<Vertex> vertices;
  vertices.emplace_back(0,true);
  for (int k=1; k<numnodes; ++k)
    vertices.emplace_back(k);
  
  /*
  vector<Vertex *> vertices;
  vertices.push_back(&A);
  vertices.push_back(&B);
  vertices.push_back(&C);
  vertices.push_back(&D);
  vertices.push_back(&E);
  vertices.push_back(&F);
  */

  int adj_mat[numnodes][numnodes];
  for (int i=0; i<numnodes; ++i)
    for (int j=0; j<numnodes; ++j)
      adj_mat[i][j] = 0;

  adj_mat[0][1] = 4;
  adj_mat[1][0] = 4;
  adj_mat[0][2] = 2;
  adj_mat[2][0] = 2;
  adj_mat[1][2] = 1;
  adj_mat[2][1] = 1;
  adj_mat[1][3] = 5;
  adj_mat[3][1] = 5;
  adj_mat[1][4] = 4;
  adj_mat[4][1] = 4;
  adj_mat[3][5] = 1;
  adj_mat[5][3] = 1;
  adj_mat[4][5] = 8;
  adj_mat[5][4] = 8;
  adj_mat[2][5] = 10;
  adj_mat[5][2] = 10;

  for (int i=0; i<numnodes; ++i) {
    for (int j=0; j<numnodes; ++j) {
      if (0 != adj_mat[i][j]) {
	vertices[i].add_connection(j);
      }
    }
  }

  bool path_not_found = true;
  int vertex_distances[6] = {0,0,0,0,0};
  int index = 0;
  int minimum_index = 0;
  for (int p=0; p<numnodes; ++p) {
  //while(path_not_found) {
    int minimum = 10000000;//intentionally obscenely large number
    while (vertices[index].is_discovered()) {
      for (vector<int>::size_type i=0; i!=vertices[index].get_connections().size(); ++i) {
	if (minimum > adj_mat[vertices[index].get_id()][vertices[index].get_connections()[i]]) {
	  minimum = adj_mat[vertices[index].get_id()][vertices[index].get_connections()[i]];
	  minimum_index = vertices[index].get_connections()[i];
	}
      }
      ++index;
    }
    vertex_distances[minimum_index]+=minimum;
    vertices[minimum_index].make_discovered();
    index = 0;
    if (minimum_index == numnodes-1)
      path_not_found = false;
  }
    
  cout << "Minimum path length: " << vertex_distances[minimum_index] << endl;

  /*
  for (int i=0; i<numnodes; ++i) {
    for (int j=0; j<numnodes; ++j) {
      cout << adj_mat[i][j] << " ";
    }
    cout << endl;
  }
  */

  return 0;
}
