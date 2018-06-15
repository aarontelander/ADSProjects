#include <iostream>
#include <vector>
using namespace std;

bool invector(int x, vector<int> v) {
	for (int i=0; i<v.size(); i++) {
		if (x == v[i]) {
			return true;
		}
	}
	return false;
}

// example1.txt is from the book
// example2.txt is a made up graph of the twin cities.

int main() {
	int numnodes;
	cin >> numnodes;
	vector<int> nodes;
	int cur;
	int next;
	cin >> cur;
	nodes.push_back(cur);
	vector<int> nodes_used;
	nodes_used.push_back(cur);
	cin >> next;
	nodes.push_back(next);
	while (nodes.size() != numnodes) {
		cin >> next;
		if (next == cur) {
			cin >> next;
			nodes.push_back(next);
		}
		else {
			if (invector(next, nodes)) {
				cin >> next;
			}
			else {
				cur = next;
				nodes_used.push_back(cur);
				cin >> next;
				nodes.push_back(next);
			}
		}
	}
	for (int k=0; k<nodes_used.size(); k++) {
		cout << nodes_used[k] << endl;
	}
	return 0;
}
