// 14889.cc
// brute-force

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

void CalcDiff(std::vector<std::vector<int>> &table, std::vector<int> &players, int N, int &min_diff) {
  int score_start = 0;
  for (int i = 0; i < N/2; ++i) {
    for (int j = 0; j < N/2; ++j) {
      score_start += table[players.at(i)][players.at(j)];
      score_start += table[players.at(j)][players.at(i)];
    }      
  }
  int score_link = 0;
  for (int i = N/2; i < N; ++i) {
    for (int j = N/2; j < N; ++j) {
      score_link += table[players.at(i)][players.at(j)];
      score_link += table[players.at(j)][players.at(i)];
    }      
  }
  int ret = std::abs(score_start - score_link);
  if (ret < min_diff) {min_diff = ret;}
  return;
}

void print(const std::vector<int>& v)
{
    for (int e : v) {
        std::cout << " " << e;
    }
    std::cout << std::endl;
}

int main() {
  int N; std::cin >> N;
  std::vector<std::vector<int>> table;
  table.resize(N, std::vector<int>(N));
  for (auto &row : table) {
    for (auto &elem : row) {
      std::cin >> elem;
    }
  }
  std::vector<int> players;
  players.resize(N);
  std::iota(players.begin(), players.end(), 0);
  int min_diff = 100 * (N-1) * (N-2);
  do {
    print(players);
    CalcDiff(table, players, N, min_diff);
  } while (std::next_permutation(players.begin(), players.end()));
  std::cout << min_diff << std::endl;

  return 0;
}