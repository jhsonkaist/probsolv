// 14500.cc
// brute-force

#include <iostream>
#include <vector>
#include <algorithm>

// dy, dx
const int cover_type[13][4][2] = {
  { {0, 0}, {0, 1}, {0, 2}, {0, 3} }, // ----
  { {0, 0}, {0, 1}, {1, 1}, {1, 0} }, // ㅁ
  { {0, 0}, {1, 0}, {2, 0}, {2, 1} }, // L
  { {0, 0}, {1, 0}, {1, 1}, {2, 1} }, // ㄱㄴ
  { {0, 0}, {0, 1}, {1, 1}, {0, 2} }, // ㅜ
  { {0, 0}, {1, 0}, {2, 0}, {3, 0} }, // l
  { {0, 0}, {1, 0}, {0, 1}, {0, 2} }, // 
  { {0, 0}, {0, 1}, {1, 1}, {2, 1} },
  { {1, 0}, {1, 1}, {1, 2}, {0, 2} },
  { {1, 0}, {1, 1}, {0, 1}, {0, 2} },
  { {0, 0}, {1, 0}, {2, 0}, {1, 1} },
  { {1, 0}, {0, 1}, {1, 1}, {2, 1} },
  { {0, 1}, {1, 0}, {1, 1}, {1, 2} }
};

int CalcScore(std::vector<std::vector<int>> &table, int type,
              int py, int px, int N, int M) {
  int score = 0;
  for (int i = 0; i < 4; ++i) {
    const int ny = py + cover_type[type][i][0];
    const int nx = px + cover_type[type][i][1];
    if (ny < 0 || ny >= N ||
        nx < 0 || nx >= M) {
      return 0;
    }
    else {score += table[ny][nx];}
  }
  return score;
}

int main() {
  int N, M; std::cin >> N >> M;
  std::vector<std::vector<int>> table;
  table.resize(N, std::vector<int>(M));
  for (auto &row : table) {
    for (auto &elem : row) {
      scanf("%d", &elem);
    }
  }
  int ret = 0;
  int score;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      for (int type = 0; type < 13; ++type) {
        score = CalcScore(table, type, i, j, N, M);
        ret = (ret < score) ? score : ret;
      }
    }
  }

  for (auto &row : table) {
    std::reverse(row.begin(), row.end());
  }
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      for (int type = 0; type < 13; ++type) {
        score = CalcScore(table, type, i, j, N, M);
        ret = (ret < score) ? score : ret;
      }
    }
  }

  std::cout << ret << std::endl;

  return 0;
}