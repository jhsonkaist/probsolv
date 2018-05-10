// 1182.cc
// brute-force

#include <iostream>
#include <vector>
#include <algorithm>

int countSubsets(int sum, int S, std::vector<int>& nums, int toDecide) {
  if (toDecide == 0) {
    if (sum == S) { return 1; }
    else { return 0; }
  }
  int ret = 0;
  int currIndex = nums.size() - toDecide;
  ret += countSubsets(sum, S, nums, toDecide - 1);
  ret += countSubsets(sum + nums.at(currIndex), S, nums, toDecide - 1);
  return ret;
}

int main() {
  int N, S, number;
  std::cin >> N >> S;
  std::vector<int> nums;
  for (int i = 0; i < N; ++i) {
    std::cin >> number;
    nums.emplace_back(number);
  }
  std::sort(nums.begin(), nums.end());
  //nums.erase(std::unique(nums.begin(), nums.end()), nums.end());
  int ret = countSubsets(0, S, nums, nums.size());
  if (S == 0) { --ret; }
  std::cout << ret << std::endl;
  return 0;
}