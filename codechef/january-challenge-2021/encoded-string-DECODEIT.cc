#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int t;
  cin >> t;

  while ( t-- ) {
    int n;
    string s, answer;
    cin >> n >> s;
    for ( int i = 0; i < n; i += 4 ) {
      int number = 0;
      for ( int j = 0; j < 4; ++j ) {
        number += (s[i + j] - '0') * (1 << (3 - j));
      }
      answer.push_back(char('a' + number));
    }
    cout << answer << '\n';
  }
  return 0;
}