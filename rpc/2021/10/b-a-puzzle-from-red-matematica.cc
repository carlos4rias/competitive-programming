#include <iostream>
using namespace std;

string multiply_big_number(string& n, int k) {
  string result;
  int carry = 0;
  for (int i = n.size() - 1; i >= 0; --i) {
    int cur = (n[i] - '0') * k + carry;
    carry = cur / 10;
    result.push_back(char((cur % 10) + '0')); 
  }
  result.push_back(char(carry + '0')); 
  return result;
}

int main() {
  int k;
  string d;
  while ( cin >> d >> k &&  k ) {
    string num(k, d[0]);
    string result = multiply_big_number(num, atoi(d.c_str()));
    int l = 0, r = 0;
    int answer = 0;
    int cur_sum = 0;
    int carry = 0;

    for (int i = 0; i < k; ++i) {
      cur_sum += (result[r] - '0');
      answer += (carry + cur_sum) % 10;
      carry = (carry + cur_sum) / 10;
      r++;
    }
    cur_sum += (result[r] - '0');
    for (int i = 0; i < k; ++i) {
      cur_sum -= (result[l] - '0');
      answer += (carry + cur_sum) % 10;
      carry = (carry + cur_sum) / 10;
      l++;
    }
    cout << answer + carry << endl;
  }
  return 0;
}