#include <iostream>
using namespace std;

#define endl '\n';

int calc_divisors(int x) {
  int divisors = 0;
  for (int i = 1; i * i <= x; ++i) {
    if (x % i == 0) {
      divisors += i * i != x ? 2 : 1;
    }
  }
  return divisors;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int maxii = 0;
  for (int i = 1; i < 100000000; ++i) {
    int n_div = calc_divisors(i);
    if (n_div > maxii) {
      cout << i << " div " << calc_divisors(i) << endl;
      maxii = n_div;
    }
  } 
  return 0;
  int t; cin >> t;
  while ( t-- ) {
    int x, maxi = 1, answer = 1 ;
    cin >> x;
    for (int i = 2; i <= x; ++i) {
      int n_divisors = calc_divisors(i);
      if (n_divisors > maxi) {
        maxi = n_divisors, answer = i;
      }
    }
    cout << answer << endl;
  }

  return 0;
}
