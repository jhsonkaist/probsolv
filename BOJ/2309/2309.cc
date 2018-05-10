// 2309.cc
// brute-force

#include <iostream>
#include <algorithm>
#include <vector>

void pick(int sum, int toPick, std::vector<int>& heights, std::vector<int>& picked) {
  if (toPick == 0) {
    if (sum == 100) {
      for (int i = 0; i < 7; i++) {
        std::cout << heights.at(picked.at(i)) << std::endl;  
      }
      exit(0);
    }
    return;
  }
  int smallest = picked.empty() ? 0 : picked.back() + 1;
  for (int next = smallest; next < 9; ++next) {
    picked.push_back(next);
    pick(sum + heights.at(next), toPick - 1, heights, picked);
    picked.pop_back();
  }
}

int main() {
  std::vector<int> heights;
  std::vector<int> picked;
  int height;
  for (int i = 0; i < 9; ++i) {
    std::cin >> height;
    heights.emplace_back(height);
  }
  std::sort(heights.begin(), heights.end());
  pick(0, 7, heights, picked);
  return 0;
}
