#include <iostream>
#include <string>

using namespace std;

int main(){
  int N;
  cin >> N;
  string S;
  cin >> S;
  string first_half = S.substr(0, N), second_half = S.substr(N, 2 * N);
  int Q;
  cin >> Q;
  for (int q = 0; q < Q; ++q){
    int T, A, B;
    cin >> T >> A >> B;
    --A, --B;
    if (T == 1)
      swap((A < N ? first_half[A] : second_half[A - N]), ((B < N ? first_half[B] : second_half[B - N])));
    else
      swap(first_half, second_half);
  }
  cout << first_half << second_half << endl;
  return 0;
}