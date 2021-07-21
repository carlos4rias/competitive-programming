#include <iostream>
#include <vector>
using namespace std;

int main() {
  int t;
  cin >> t;
  int k, n, m;
  
  while (t--) {
    cin >> k >> n >> m;
    vector<int> a(n), b(m);
    vector<int> answer;
    for (int& i : a) cin >> i;
    for (int& i : b) cin >> i;

    int i = 0, j = 0;
    int lines = k;
    bool advanced = false;

    while (i < n || j < m) {
      advanced = false;
      if (i < n  && (a[i] == 0 || a[i] <= lines)) {
        lines += a[i] == 0;
        answer.push_back(a[i]);
        advanced = true;
        i++;
      }
      if (j < m && (b[j] == 0 || b[j] <= lines)) {
        lines += b[j] == 0;
        answer.push_back(b[j]);
        advanced = true;
        j++;
      }
      if (!advanced) break;
    }

    if (!advanced) cout << -1 << endl;
    else {
      for (int i: answer) cout << i << " "; cout << endl;
    }

  } 
  return 0;
}