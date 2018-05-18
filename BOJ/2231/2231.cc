// 2231.cc
// brute-force

#include <vector>
#include <cmath>
#include <iostream>

int DivSum(int i) {
  int sum = i;
  while (i > 0) {
    sum += i % 10;
    i /= 10;
  }
  return sum;
}

int main() {
  int N; std::cin >> N;
  int start = (N > 60) ? (N - 60) : 1;
  int my_generate;
  for (int i = start; i < N; i++) {
    my_generate = DivSum(i);
    if (my_generate == N) {
      std::cout << i << std::endl;
      return 0;
    }
  }
  std::cout << 0 << std::endl;
  return 0; 
}