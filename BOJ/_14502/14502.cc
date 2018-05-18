// 14502.cc
// DFS + brute-force

#include <iostream>
#include <vector>
#include <stack>

struct Point_2 {
  int x;
  int y;
};

const Point_2 dxy[4] = {{-1,0}, {1,0}, {0,-1}, {0,1}};

int calc_safe_area(std::vector<std::vector<int>> table, int nx, int ny) {
  std::stack<Point_2> stk;
  
  for (int i = 0; i < nx; ++i) {
    for (int j = 0; j < ny; ++j) {

    }
  }
} 

int main() {
  int nx, ny; std::cin >> nx >> ny;
  std::vector<std::vector<int>> table;
  table.resize(nx, std::vector<int>(ny));
  
  // input
  for (auto &ty : table) {
    for (auto &txy : ty) {
      std::cin >> txy;
    }
  }

  int max_area = nx*ny;
  int curr_area;
  int end_wall_number = (nx*ny)*(nx*ny)*(nx*ny);
  for (int wall_number = 0; wall_number < end_wall_number; wall_number++) {
    curr_area = calc_safe_area(table, nx, ny);
    max_area = (curr_area > max_area) ? curr_area : max_area;
  }
  std::cout << max_area << std::endl;
  return 0;
}