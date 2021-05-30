#include <iostream>
#include <random>

int main(){
  int N = 20;
  char color[] = "RGB";
  std::cout << N << "\n";
  std::mt19937_64 engine;
  std::uniform_int_distribution<long int> a(1, 500);
  std::uniform_int_distribution c(0, 2);
  for (int n = 0; n < 2 * N; ++n)
    std::cout << a(engine) << " " << color[c(engine)] << "\n";
  std::cout << std::flush;
}