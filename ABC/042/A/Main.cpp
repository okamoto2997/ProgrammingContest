#include <iostream>
#include <ctime>
#include <filesystem>

#include "../lib/log.hpp"

using namespace std;

int main(){
  int A, B, C;
  cin >> A >> B >> C;

  int count[2] = {};
  switch (A){
  case 5: count[0]++; break;
  case 7: count[1]++; break;
  }
  switch (B){
  case 5: count[0]++; break;
  case 7: count[1]++; break;
  }
  switch (C){
  case 5: count[0]++; break;
  case 7: count[1]++; break;
  }

  cout << (count[0] == 2 && count[1] == 1 ? "YES" : "NO") << endl;

  return 0;
}