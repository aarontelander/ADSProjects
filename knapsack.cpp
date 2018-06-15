#include <iostream>
#include <vector>
using namespace std;

int main() {
  const int weights[4] = {12,6,8,4};
  const int values[4] = {30,14,16,9};
  const int cap = 20;
  
  vector<int> K;
  vector <int> K_weight;
  K.push_back(0);
  K_weight.push_back(0);

  for (int w = 1; w<=cap; w++) {
    int largest_k_index = 0;
    int largest_value = 0;
    int associated_weight = 0;

    for (int j = 0; j < w; j++) {
      for (int i = 0; i < 4; i++) {
	if (values[i]+K[j] > largest_value && weights[i]+K_weight[j] <= w) {
	  largest_value = values[i]+K[j];
	  largest_k_index = j;
	  associated_weight = weights[i];
	}
      }
    }

    K.push_back(largest_value);
    K_weight.push_back(K_weight[largest_k_index]+associated_weight);


    cout << w << ".\t" << K[w] << endl;
  }
  return 0;
}
