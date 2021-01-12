#include <algorithm>
#include <iostream>
#include <numeric>
#include <queue>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int tc;
  cin >> tc;
  while ( tc-- ) {
    int n, m, x;
    int sum_a = 0;
    int sum_b = 0;
    priority_queue<int> B;
    priority_queue<int, vector<int>, greater<int> > A;
    cin >> n >> m;

    for ( int i = 0; i < n; ++i ) {
      cin >> x;
      sum_a += x;
      A.push(x);
    }

    for ( int i = 0; i < m; ++i ) {
      cin >> x;
      sum_b += x;
      B.push(x);
    }

    int answer = 0;

    while ( sum_a < sum_b && A.top() < B.top() ) {
      int a_top = A.top(); A.pop();
      int b_top = B.top(); B.pop();
      sum_a = sum_a - a_top + b_top;
      sum_b = sum_b - b_top + a_top;
      A.push(b_top);
      B.push(a_top);
      answer++;
    }

    cout << ( sum_a > sum_b ? answer : -1 ) << endl;
  }
  return 0;
}
