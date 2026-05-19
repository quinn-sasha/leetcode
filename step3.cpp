class Solution {
 public:
  int uniquePaths(int m, int n) {
    std::vector<std::vector<int>> paths = std::vector(m, std::vector<int>(n));
    for (int col = 0; col < n; ++col) {
      paths[0][col] = 1;
    }
    for (int row = 0; row < m; ++row) {
      paths[row][0] = 1;
    }
    for (int row = 1; row < m; ++row) {
      for (int col = 1; col < n; ++col) {
        paths[row][col] = paths[row - 1][col] + paths[row][col - 1];
      }
    }
    return paths[m - 1][n - 1];
  }
};
