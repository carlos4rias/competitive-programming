#include <algorithm>
#include <cassert>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int tc;
  cin >> tc;
  while ( tc-- ) {
    int n, m;
    cin >> n >> m;
    vector<int> A(n), B(m);
    for ( int &x : A ) cin >> x;
    for ( int &x : B ) cin >> x;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int sum_a = accumulate(A.begin(), A.end(), 0);
    int sum_b = accumulate(B.begin(), B.end(), 0);
    int ix = 0, jx = m - 1;
    int answer = 0;

    while ( ix < n && jx >= 0 && A[ix] < B[jx] && sum_a <= sum_b ) {
      assert(sum_a > 0);
      assert(sum_b > 0);
      sum_a = sum_a - A[ix] + B[jx];
      sum_b = sum_b - B[jx] + A[ix];
      ix++; jx--;
      answer++;
    }

    cout << ( sum_a > sum_b ? answer : -1 ) << endl;
  }
  return 0;
}
