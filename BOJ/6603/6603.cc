// 6603.cc
// brute-force

#include <iostream>
#include <vector>

void PrintPicked(std::vector<int>& nums, std::vector<int>& picked) {
  for (int i = 0; i < picked.size(); ++i) {
    std::cout << nums.at(picked.at(i)) << " ";
  }
  std::cout << std::endl;
}

void PickNum(int k, int toPick, 
            std::vector<int>& nums, std::vector<int>& picked) {
  if (toPick == 0) {
    PrintPicked(nums, picked);
    return;
  }
  int smallest = picked.empty() ? 0 : picked.back() + 1;
  for (int next = smallest; next < k; ++next) {
    picked.push_back(next);
    PickNum(k, toPick - 1, nums, picked);
    picked.pop_back();
  }
}

int main() {
  int k, number;
  std::cin >> k;
  std::vector<int> nums;
  std::vector<int> picked;
  while (k > 0) {
    nums.clear();
    picked.clear();
    for (int i = 0; i < k; ++i) {
      std::cin >> number;
      nums.emplace_back(number);
    }
    PickNum(k, 6, nums, picked);
    std::cin >> k;
    if (k > 0) std::cout << std::endl;
  }
  return 0;
}