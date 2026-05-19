#include <vector>

class Solution {
 public:
  int uniquePaths(int m, int n) {
    std::vector<std::vector<int>> paths =
        std::vector(m + 1, std::vector<int>(n + 1, 0));
    paths[0][1] = 1;  // dummy path
    for (int row = 1; row <= m; ++row) {
      for (int col = 1; col <= n; ++col) {
        paths[row][col] = paths[row - 1][col] + paths[row][col - 1];
      }
    }
    return paths[m][n];
  }
};
