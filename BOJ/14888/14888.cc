// 14888.cc
// brute-force

#include <iostream>
#include <cmath>
#include <vector>

void CalcExp(std::vector<int>& seq, std::vector<int>& num_op, 
            int curr, int &max, int &min, int toPick) {
  if (toPick == 0) {
    if (curr > max) {
      max = curr;
    }
    if (curr < min) {
      min = curr;
    }
    return;
  }
  int next = seq.at(seq.size() - toPick); 
  if (num_op.at(0)) {
    --num_op.at(0);
    CalcExp(seq, num_op, curr + next, max, min, toPick - 1);
    ++num_op.at(0);
  }
  if (num_op.at(1)) {
    --num_op.at(1);
    CalcExp(seq, num_op, curr - next, max, min, toPick - 1);
    ++num_op.at(1);
  }
  if (num_op.at(2)) {
    --num_op.at(2);
    CalcExp(seq, num_op, curr * next, max, min, toPick - 1);
    ++num_op.at(2);
  }
  if (num_op.at(3) && next != 0) {
    --num_op.at(3);
    CalcExp(seq, num_op, curr / next, max, min, toPick - 1);
    ++num_op.at(3);
  }
  return;
  
}

int main () {
  int N; std::cin >> N;
  int num;
  std::vector<int> seq;
  for (int i = 0; i < N; ++i) {
    std::cin >> num;
    seq.emplace_back(num);
  }
  std::vector<int> num_op = {0, 0, 0, 0};
  for (int i = 0; i < 4; ++i) {
    std::cin >> num;
    num_op.at(i) = num;
  }

  int max = -1000000001;
  int min =  1000000001;

  CalcExp(seq, num_op, seq.at(0), max, min, N-1);

  std::cout << max << std::endl << min << std::endl;

  return 0;
}