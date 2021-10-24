#include <iostream>
using namespace std;

#define endl '\n';

long long get_points(int n) {
  if (n - 1 < 0) return 0;
  return 1LL* n * (n - 1);
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int t;
  cin >> t;
  while ( t-- ) {
    int n, k;
    cin >> n >> k;
    long long points = get_points(n) - get_points(n - k);
    long long result = points / k;
    result -= result % 2 ? 1 : 0;

    cout << result << endl;

  }
  return 0;
}