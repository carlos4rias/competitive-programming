#include <iostream>
using namespace std;

int main() {
  int t, x;
  cin >> t;
  while (t--) {
    bool answer = false;
    for ( int i = 0; i < 3; ++i ) {
      cin >> x;
      answer = x == 7 ? true : answer;
    }
    cout << (answer ? "YES" : "NO") << endl;
  }
  return 0;
}
