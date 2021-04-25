#include <iostream>
#include <vector>
#include <string>

using i64 = int64_t;
using u64 = uint64_t;

constexpr u64 gcd(u64 m, u64 n) {
  return m == n ? m : m < n ? (n % m == 0 ? m : gcd(n % m, m)) : (m % n == 0 ? n : gcd(n, m % n));
}
using namespace std;

int main() {
  u64 A, B, C;
  cin >> A >> B >> C;

  u64 size = gcd(gcd(A, B), C);

  cerr << "size: " << size << "\n";
  cout << (A / size - 1) + (B / size - 1) + (C / size - 1) << endl;

  return 0;
}