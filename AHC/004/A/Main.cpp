#include <algorithm>
#include <cmath>
#include <cstdarg>
#include <iostream>
#include <map>
#include <random>
#include <set>
#include <string>
#include <sys/time.h>
#include <vector>

#include "lib/log.hpp"
#include "lib/utility.hpp"

using namespace std;
using namespace lib;

bool is_substr(const string &str, int N, const vector<vector<char>> &G) {
  for (int r = 0; r < N; ++r)
    for (int c = 0; c < N; ++c) {
      bool is_accepted = true;
      for (size_t i = 0; i < str.size(); ++i)
        if (G[r][(c + i) % N] != str[i]) {
          is_accepted = false;
          break;
        }
      if (!is_accepted) continue;
      return true;
    }

  for (int r = 0; r < N; ++r)
    for (int c = 0; c < N; ++c) {
      bool is_accepted = true;
      for (size_t i = 0; i < str.size(); ++i)
        if (G[(r + i) % N][c] != str[i]) {
          is_accepted = false;
          break;
        }
      if (!is_accepted) continue;
      return true;
    }

  return false;
}

int count(int N, const vector<string> &s, const vector<vector<char>> &G) {
  int counter = 0;
  for (auto &str : s)
    if (is_substr(str, N, G) || is_substr(reverse(str), N, G)) counter++;
  return counter;
}

int choose_best(int cur_score, int r, int c, int N, const vector<string> &s,
                vector<vector<char>> &G) {
  int record = cur_score;
  int record_char = G[r][c];
  int cur_gene = G[r][c];

  for (char ch = 'A'; ch <= 'H'; ++ch)
    if (ch != cur_gene) {
      G[r][c] = ch;
      if (int cur_score = count(N, s, G); cur_score > record) {
        record = cur_score;
        record_char = ch;
      }
    }
  G[r][c] = record_char;
  return record;
}

void rotate(bool row, bool reverse, int index, int N, vector<vector<char>> &G) {
  if (row)
    if (reverse) {
      char tmp = G[index][N - 1];
      for (int c = 0; c < N - 1; ++c)
        G[index][c + 1] = G[index][c];
      G[index][0] = tmp;
    } else {
      char tmp = G[index][0];
      for (int c = 1; c < N; ++c)
        G[index][c - 1] = G[index][c];
      G[index][N - 1] = tmp;
    }
  else {
    if (reverse) {
      char tmp = G[N - 1][index];
      for (int r = 0; r < N - 1; ++r)
        G[r + 1][index] = G[r][index];
      G[0][index] = tmp;
    } else {
      char tmp = G[0][index];
      for (int r = 1; r < N; ++r)
        G[r - 1][index] = G[r][index];
      G[N - 1][index] = tmp;
    }
  }
}

int main() {
  timer t;
  t.start();
  auto [N, M] = read_elems<int, int>();
  vector<string> s(M);
  for (auto &str : s)
    str = read<string>();

  vector<vector<char>> G(N, vector<char>(N, '.'));
  vector<vector<char>> prev_G(N, vector<char>(N, '.'));
  mt19937_64 engine;
  uniform_int_distribution<int> rand(0, 7);
  uniform_int_distribution<int> pos(0, N - 1);
  uniform_int_distribution<int> chg(1, 7);
  uniform_real_distribution<double> choose_mixier(0, 1);
  for (int r = 0; r < N; ++r)
    for (int c = 0; c < N; ++c)
      G[r][c] = 'A' + rand(engine);

  int score = count(N, s, G);

  while (true) {
    if (t.watch() > 2.9) break;
    int new_score = 0;
    prev_G = G;
    if (auto mixier = choose_mixier(engine); mixier < 0) {
      int r = pos(engine);
      int c = pos(engine);
      // G[r][c] = ((G[r][c] - 'A' + chg(engine)) % 8) + 'A';
      // new_score = count(N, s, G);
      new_score = choose_best(score, r, c, N, s, G);
    } else {
      int selector = rand(engine);
      bool row = selector & 1;
      bool reverse = selector & 2;
      int index = pos(engine);
      rotate(row, reverse, index, N, G);

      new_score = count(N, s, G);
    }

    if (new_score > score) {
      INFO("new record!");
      INFO("score: %d", new_score);
      score = new_score;
      continue;
    } else {
      G = prev_G;
    }
  }

  for (auto &g : G) {
    for (auto &c : g)
      cout << c;
    cout << "\n";
  }
  cout << endl;

  return 0;
}