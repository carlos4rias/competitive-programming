#include <iostream>
#include <vector>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> answer = {0};
    
    for (int& i: a) cin >> i;
    int prev = a[0];

    for (int i = 1; i < n; ++i) {
      int next = 0;
      for (int bit = 0; bit < 32; bit++) {
        int pot = 1 << bit;
        if ((prev & pot) != 0 && (a[i] & pot) == 0) {
          next |= pot;
        }
      }
      answer.emplace_back(next);
      prev = a[i] ^ next;
    }

    for (int i: answer) cout << i << " "; cout << endl;
  }
  return 0;
}