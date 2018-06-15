#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

const int num_nodes = 6;

void print_graph(vector<vector<int>> graph) {
	for (int i=0; i<num_nodes; i++) {
		for (int j=0; j<num_nodes; j++) {
			cout << graph[i][j] << '\t';
		}
		cout << endl;
	}
}

void init_graph(vector<vector<int>> &graph) {
	graph[0][1] = 1;
	graph[0][3] = 2;
	graph[0][4] = 5;
	graph[1][2] = 2;
	graph[1][3] = 4;
	graph[1][4] = 5;
	graph[2][3] = 5;
	graph[2][4] = 1;
	graph[2][5] = 4;
	graph[3][4] = 3;
	graph[4][5] = 1;
}

void path_finder(vector<vector<int>> &graph) {
	for (int k=0; k<num_nodes; k++) {
		for (int i=0; i<num_nodes; i++) {
			for (int j=0; j<num_nodes; j++) {
				if (graph[i][j] > graph[i][k] + graph[k][j]) {
					graph[i][j] = graph[i][k] + graph[k][j];
				}
			}
		}
	}
}

int main() {
	vector<vector<int>> graph;
	for (int i=0; i<num_nodes; i++) {
		vector<int> tmp;
		graph.push_back(tmp);
	}

	for (int i=0; i<num_nodes; i++) {
		for (int j=0; j<num_nodes; j++) {
			if (i==j) {
				graph[i].push_back(0);
			}
			else {
				graph[i].push_back(999);
			}
		}
	}

	init_graph(graph);
	cout << "Initial Graph:" << endl;
	print_graph(graph);
	cout << endl;
	cout << "Solution Matrix: " << endl;
	path_finder(graph);
	print_graph(graph);
	cout << endl;
	cout << "The Shortest Path has a length of: " <<
	graph[0][num_nodes-1] << endl;

	return 0;
}
