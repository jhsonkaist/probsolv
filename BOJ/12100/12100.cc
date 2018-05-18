// 12100.cc
// brute-force
// 2048 game

#include <iostream>
#include <vector>

void ProjTable(std::vector<std::vector<int>> &table) {
  std::vector<int> new_row;
  for (auto &row : table) {
    new_row.clear();
    int operand = 0;
    for (auto &elem : row) {
      if (elem == 0) {continue;}
      if (operand == 0) {operand = elem;}
      else {
        if (elem == operand) {
          new_row.push_back(elem+operand);
          operand = 0;
        }
        else {
          new_row.push_back(operand);
          operand = elem;
        }
      }
    }
    if (operand > 0) {new_row.push_back(operand);}
    new_row.resize(table.size(), 0);
    row = new_row;
  }
  return;

}

void TurnTable(std::vector<std::vector<int>> &table) {
  std::vector<std::vector<int>> tr_table;
  tr_table.resize(table.size(), std::vector<int>(table.size()));
  for (int i = 0; i < table.size(); ++i) {
    for (int j = 0; j < table.size(); ++j) {
      tr_table[i][j] = table[j][table.size()-i-1];
    }
  }
  for (int i = 0; i < table.size(); ++i) {
    for (int j = 0; j < table.size(); ++j) {
      table[i][j] = tr_table[i][j];
    }
  }
  return;
}

void ProcessTable(std::vector<std::vector<int>> table, int turns, int &max) {
  if (turns == 0) {
    for (auto &row : table) {
      for (auto &elem : row) {
        if (max < elem) max = elem;
      }
    }
    return;
  }
  
  for (int i = 0; i < 4; ++i) {
    TurnTable(table);
    //std::cout << table[0][1] << " ";
    std::vector<std::vector<int>> new_table;
    new_table.resize(table.size(), std::vector<int>(table.size()));
    for (int i = 0; i < table.size(); ++i) {
      for (int j = 0; j < table.size(); ++j) {
        new_table[i][j] = table[i][j];
      }
    }
    ProjTable(new_table);
    ProcessTable(new_table, turns - 1, max);
  }
  return;
}

int main () {
  int board_size; std::cin >> board_size;
  std::vector<std::vector<int>> table;
  table.resize(board_size, std::vector<int>(board_size));

  for (auto &row : table) {
    for (auto &elem : row) {
      std::cin >> elem;
    }
  }
  
  int max = 0;
  ProcessTable(table, 5, max);

  std::cout << max << std::endl;

  return 0;
}