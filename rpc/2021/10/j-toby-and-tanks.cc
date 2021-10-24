#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define endl '\n';

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int n, q, x;
  while ( cin >> n >> q ) {
    vector<int> tanks(n), answer(q);
    cin >> tanks[0]; tanks [0] = 1;

    for (int i = 1; i < n; ++i) {
      cin >> tanks[i];
      tanks[i] = tanks[i] + tanks[i - 1];
    }

    for (int i = 0; i < q; ++i) {
      cin >> x;
      answer[i] = (upper_bound(tanks.begin(), tanks.end(), x) - tanks.begin());
    }

    for (int i = 0; i < q; ++i) {
      if (i) cout << " ";
      cout << answer[i];
    }
    cout << endl;
  }

  return 0;
}
