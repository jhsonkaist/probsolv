// 10448.cc
// brute-force

#include <iostream>
#include <vector>

int CheckTriSum(int num, std::vector<int>& tri_nums, int toPick) {
  if (num < 0) return 0;
  if (toPick == 0) {
    if (num == 0) {
      return 1;
    }
    else return 0;
  }
  int ret = 0;
  for (auto &tri_num : tri_nums) {
    ret += CheckTriSum(num - tri_num, tri_nums, toPick - 1);
  }
  ret = (ret > 0) ? 1 : 0;
  return ret;
}

int main() {
  int T; std::cin >> T;
  std::vector<int> tri_nums;

  int tri_num = 1;
  int num = 1;
  while (tri_num <= 1000) {
    tri_nums.emplace_back(tri_num);
    ++num; tri_num = (num)*(num+1)/2;
  }
  int ret;
  while (T) {
    std::cin >> num;
    ret = CheckTriSum(num, tri_nums, 3);
    std::cout << ret << std::endl;
    --T;
  }
  return 0;
}