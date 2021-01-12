#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

const int oo = 1e9;
const int MX = 105;
int memo[MX][MX][MX];
int color[MX][MX][MX];

int solve(int idx, int a, int b, vector<int>& heights, int& k, int& c) {
  if ( color[idx][a][b] == c ) return memo[idx][a][b];
  if ( idx == heights.size() ) {
    return (a >= k && b >= k) ? 0 : oo;
  }
  int answer = solve(idx + 1, a, b, heights, k, c);
  answer = min(answer, solve(idx + 1, min(a + heights[idx], k), b, heights, k, c) + 1);
  answer = min(answer, solve(idx + 1, a, min(b + heights[idx], k), heights, k, c) + 1);
  color[idx][a][b] = c;
  return memo[idx][a][b] = answer;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int tc;
  cin >> tc;
  int col = 1;
  memset(color, 0, sizeof(color));

  while ( tc-- ) {
    int n, k;
    int sum_a = 0;
    int sum_b = 0;

    cin >> n >> k;
    vector<int> heights(n);

    for ( int& x : heights ) cin >> x;
    int answer = solve(0, 0, 0, heights, k, col);

    cout << ( answer != oo ? answer : -1 ) << endl;
    col++;
  }
  return 0;
}
