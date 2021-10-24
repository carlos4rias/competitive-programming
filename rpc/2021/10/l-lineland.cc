#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  while (cin >> n) {
    vector<pair<int, int>> plants(n);
    for (auto& x : plants) cin >> x.first >> x.second;
    sort(plants.begin(), plants.end());
    
    int city = -1, coverage = -1;
    for (int i = 0; i < n; ++i) {
      pair<int, int> current = {plants[i].first + plants[i].second, 0};
      int distance = lower_bound( plants.begin(), plants.end(), current ) - plants.begin() - i; 
      if (distance - 1 > coverage) {
        coverage = distance - 1;
        city = plants[i].first;
      }
    }
    cout << city << " " << coverage << endl;
  }
}