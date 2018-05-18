// 1051.cc
// brute-force

#include <iostream>
#include <vector>
#include <string>

bool CheckTable(std::vector<std::vector<int>> &table, int i, int j, int req_size) {
  int a = table[i][j];
  int b = table[i][j+req_size-1];
  int c = table[i+req_size-1][j+req_size-1];
  int d = table[i+req_size-1][j];

  return ( a==b && b==c && c==d && d==a );
}

int main() {
  int N, M; std::cin >> N >> M;
  std::vector<std::vector<int>> table;
  table.resize(N, std::vector<int>(M));
  std::string inp;
  for (int i = 0; i < N; ++i) {
    std::cin >> inp;
    for (int j = 0; j < M; ++j) {
      table[i][j] = inp.at(j) - '0';
    }
  }
  int max_req_size = (N > M) ? N : M;
  int ret = 0;
  for (int req_size = 1; req_size <= max_req_size; ++req_size) {
    for (int i = 0; i < N - req_size + 1; ++i) {
      for (int j = 0; j < M - req_size + 1; ++j) {
        if (CheckTable(table, i, j, req_size)) {
          ret = req_size;
          i = N; j = M;
        }
      }
    }
  }
  std::cout << ret * ret << std::endl;
  return 0;
}