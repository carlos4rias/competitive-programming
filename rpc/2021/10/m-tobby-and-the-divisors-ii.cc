#include <iostream>
#include <vector>
using namespace std;

#define endl '\n';

const int MN = 1000005;

vector<int> calculate() {
  vector<int> primes;
  vector<bool> is_prime(MN, true);
  vector<int> max_divisors(MN, 1);

  for (int i = 2; i * i < MN; ++i) {
    if (!is_prime[i]) continue;
    primes.push_back(i);
    for (int j = i * 2; j < MN; j += i)
      is_prime[j] = false;
  }
  int max_divisor = 1;
  for (int i = 2; i < MN; ++i) {
    int divisors = 1;
    int copy_n = i;
    for (int j = 0; primes[j] * primes[j] <= copy_n && j < primes.size(); ++j) {
      if (copy_n % primes[j] == 0) {
        int cur = 0;
        while (copy_n % primes[j] == 0) {
          copy_n /= primes[j];
          cur++;
        }
        divisors *= (cur + 1);
      }
    }
    if (copy_n != 1) divisors *= 2;
    if (divisors > max_divisor) {
      max_divisors[i] = i;
      max_divisor = divisors;
    } else {
      max_divisors[i] = max_divisors[i - 1];
    }
  }
  return max_divisors;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  
  int t; cin >> t;
  vector<int> divisors = calculate();
  
  while (t--) {
    int n; cin >> n;
    cout << divisors[n] << endl;
  }
  return 0;
}