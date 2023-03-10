#include <iostream>

using namespace std;

int main() {
  int t; cin >> t;
  while (t--) {
    int n, x; cin >> n;
    int paired = 0, alone = 0, available = 0;

    for (int i = 0; i < n; i++) {
      cin >> x;
      if (x == 1) {
        if (available > 0) {
          available--; alone++;
        } else {
          alone++;
        }
      } else {
        if (alone > 2) {
          int tmp = alone - 1;
          paired += tmp / 2;
          available += alone - (tmp / 2) - (1 + tmp % 2);
          alone = 1 + tmp % 2;
        }
      }
    }
    cout << (paired + alone + available) << endl;
  }
  return 0;
}