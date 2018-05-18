// 7568.cc

#include <iostream>
#include <vector>

struct Spec {
  int weight;
  int height;
  Spec(const int w, const int h) :
    weight(w), height(h) {}
  bool operator<(const Spec& s) {
    return (weight < s.weight) && (height < s.height);
  }
};

int main() {
  int N; std::cin >> N;
  std::vector<Spec> list;
  int w, h;
  for (int i = 0; i < N; ++i) {
    std::cin >> w >> h;
    list.emplace_back(Spec(w, h));
  }
  int rank = 0;
  for (int i = 0; i < N; ++i) {
    rank = 1;
    for (int j = 0; j < N; ++j) {
      if (list.at(i) < list.at(j)) rank++;
    }
    std::cout << rank << " ";
  }
  std::cout << std::endl;
  return 0;
}