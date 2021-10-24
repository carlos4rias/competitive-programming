#include <iostream>
#include <vector>
using namespace std;

#define endl '\n';

const int dogs = 6;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int t; cin >> t;
  while ( t-- ) {
    vector<int> weights(dogs);
    for (auto& i : weights) cin >> i;

    bool answer = false;

    for (int i = 1; i < (1 << dogs); ++i) {
      int boat_a = 0;
      int boat_b = 0;
      for (int j = 0; j < dogs; ++j) {
        if ( i & (1 << j)) {
          boat_a += weights[j];
        } else {
          boat_b += weights[j];
        }
      }
      answer |= boat_a == boat_b;
    }
    cout << (answer ? "Tobby puede cruzar" : "Tobby no puede cruzar") << endl; 
  }

  return 0;
}
