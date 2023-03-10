#include <iostream>

using namespace std;

int main() {
  int t; cin >> t;
  while (t--) {
    int n, x; cin >> n;
    int positives = 0, negatives = 0;

    for (int i = 0; i < n; ++i) {
      cin >> x;
      positives += x > 0;
      negatives += x < 0;
    }

    for (int i = 1; i <= positives; i++) cout << i << " ";
    for (int i = 1; i <= negatives; i++) cout << positives - i << " ";
    cout << endl;

    int pos = 1;
    for (int i = 1; i <= positives; i++) {
      if (i <= negatives) cout << "1 0 ";
      else {
        cout << pos++ << " ";
      }
    }
    cout << endl;
  }
  return 0;
}