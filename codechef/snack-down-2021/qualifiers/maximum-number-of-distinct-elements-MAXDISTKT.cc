#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t, n, x;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<int> answer(n);
    vector<pair<int, int>> elements(n);

    for ( int i = 0; i < n; ++i ) {
      cin >> elements[i].first;
      elements[i].second = i;
    }
    sort(elements.begin(), elements.end());

    int cur_element = 0;
    for ( pair<int, int>& x: elements ) {
      answer[x.second] = cur_element;
      cur_element += cur_element < x.first ? 1 : 0;
    }

    for ( int x : answer ) cout << x << " ";
    cout << "\n";
  }
  return 0;
}
