#include <algorithm>
#include <iostream>
using namespace std;

#define endl '\n';

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int t;
  cin >> t;
  while ( t-- ) {
    int x, k;
    cin >> x >> k;
    k = x * k;

    cout << x * 2 << " ";
    cout << 1LL * k * (k - 1) << endl;

  }
  return 0;
}