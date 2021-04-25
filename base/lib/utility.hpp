#pragma once

#include <string>
#include <iostream>

std::string readline(std::istream& src = std::cin) {
  std::string buffer;
  std::getline(src, buffer);
  return buffer;
}

using i64 = int64_t;
using u64 = uint64_t;

constexpr u64 gcd(u64 m, u64 n) {
  return m == n ? m : m < n ? (n % m == 0 ? m : gcd(n % m, m)) : (m % n == 0 ? n : gcd(n, m % n));
}