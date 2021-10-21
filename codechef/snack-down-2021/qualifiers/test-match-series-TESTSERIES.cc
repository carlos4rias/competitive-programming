#include <iostream>
using namespace std;

string winner(int india, int england, int draw) {
  return (india > england ? "INDIA" : (england > india ? "ENGLAND" : "DRAW"));
}

int main() {
  int t, x;
  cin >> t;
  while (t--) {
    int india = 0, england = 0, draw = 0;
    for ( int i = 0; i < 5; ++i ) {
      cin >> x;
      draw    += x == 0;
      india   += x == 1;
      england += x == 2;
    }
    cout << winner(india, england, draw) << endl;
  }
  return 0;
}
