// 14501.cc
// brute-force

#include <iostream>
#include <vector>

int CalcMaxIncome(int day, int N,
                  std::vector<int>& times, std::vector<int>& costs) {
  if (day > N) {
    return 0;
  }
  int ret1 = 0;
  if (day + times.at(day) <= N+1) {
    ret1 = costs.at(day) + CalcMaxIncome(day + times.at(day), N, times, costs);
  }
  int ret2 = CalcMaxIncome(day + 1, N, times, costs);
  return ret1 > ret2 ? ret1 : ret2;
}

int main() {
  int N; std::cin >> N;
  std::vector<int> times{0};
  std::vector<int> costs{0};
  int t, c;
  for (int i = 0; i < N; ++i) {
    std::cin >> t >> c;
    times.emplace_back(t);
    costs.emplace_back(c);
  }
  std::cout << CalcMaxIncome(1, N, times, costs) << std::endl;
}