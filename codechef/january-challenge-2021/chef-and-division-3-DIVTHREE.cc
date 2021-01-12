#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;
  while ( t-- ) {
    int n, k, d, x;
    cin >> n >> k >> d;
    long long sum = 0;
    for ( int i = 0; i < n; ++i ) {
      cin >> x;
      sum += x;
    }

    cout << min((long long)d, sum / k) << endl;
  }
  return 0;
}