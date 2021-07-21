#include <iostream>
using namespace std;

int is_inside(int a, int b, int f) {
  return (f < min(b, a) || f > max(b, a)) ? 0 : 2;
}

int main() {
  int ax, ay, bx, by, fx, fy;
  int n;
  cin >> n;
  while ( n-- ) {
    cin >> ax >> ay;
    cin >> bx >> by;
    cin >> fx >> fy;

    int answera = abs(bx - ax);
    int answerb = abs(by - ay);

    if (ax == bx && ax == fx) {
      cout << answerb + is_inside(ay, by, fy) << endl;
    } else if (ay == by && ay == fy) {
      cout << answera + is_inside(ax, bx, fx) << endl;
    } else {
      cout << answera + answerb << endl;
    }
  }
  return 0;
}