#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  while ( n-- ) {
    string s;
    cin >> s;
    int a_idx = -1;

    for (int i = 0; i < s.size(); ++i)
      a_idx = (s[i] == 'a') ? i : a_idx;

    bool answer = a_idx != -1;
    int iz = a_idx - 1;
    int id = a_idx + 1;
    char to_find = 'b';
    while ((iz >= 0 || id < s.size()) && answer) {
      if (iz >= 0 && s[iz] == to_find) {
        iz--; to_find++;
      } else if (id < s.size() && s[id] == to_find) {
        id++; to_find++;
      } else {
        answer = false;
      }
    }
    cout << ((answer) ? "YES" : "NO") << endl;
  }
  return 0;
}