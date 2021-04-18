#include <iostream>

using namespace std;

int main(){
  int A, B;
  cin >> A >> B;

  if (A > B){
    for (int i = 1; i <= A; ++i)
      cout << i << " ";
    for (int i = 1; i <= B - 1; ++i)
      cout << -i << " ";
    cout << -(A * (A + 1) / 2 - B * (B - 1) / 2) << endl;
  }
  else{
    for (int i = 1; i <= A - 1; ++i)
      cout << i << " ";
    for (int i = 1; i <= B; ++i)
      cout << -i << " ";
    cout << -(A * (A - 1) / 2 - B * (B + 1) / 2) << endl;
  }


  return 0;
}