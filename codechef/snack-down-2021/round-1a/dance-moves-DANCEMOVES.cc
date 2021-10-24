#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;
  while ( t-- ) {
    int a, b;
    cin >> a >> b;
    int diff = abs(b - a);
    int answer = (a < b ? (diff / 2 + (diff % 2 == 0 ? 0 : 2)) : diff);
    cout << answer << endl;
  }
  return 0;
}