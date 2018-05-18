// 1018.cc
// brute-force

#include <iostream>
#include <vector>

void CheckTable(std::vector<std::vector<char>> &table, 
              int row_idx, int col_idx, int &min_exchange) {
  int ret_w = 0;
  int ret_b = 0;
  for (int i = 0; i < 8; ++i) {
    for (int j = 0; j < 8; ++j) {
      if ((i+j) % 2) {
        if (table[row_idx+i][col_idx+j] == 'W') ++ret_w;
        else ++ret_b;
      }
      else {
        if (table[row_idx+i][col_idx+j] == 'W') ++ret_b;
        else ++ret_w;
      }
    }
  }
  int ret =  (ret_w > ret_b) ? ret_b : ret_w;
  if (min_exchange > ret) min_exchange = ret;
  return;
}

int main() {
  int row_size, col_size;
  std::cin >> row_size >> col_size;

  std::vector<std::vector<char>> table;
  table.resize(row_size, std::vector<char>(col_size));

  for (auto &row : table) {
    for (auto &elem : row) {
      std::cin >> elem;
    }
  }
  int min_exchange = 64;
  
  for (int i = 0; i < row_size - 7; ++i) {
    for (int j = 0; j < col_size - 7; ++j) {
      CheckTable(table, i, j, min_exchange);
    }
  }

  std::cout << min_exchange << std::endl;

  return 0;
}