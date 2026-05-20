class Solution {
  using Grid = std::vector<std::vector<int>>;

 public:
  int uniquePathsWithObstacles(const Grid& obstacle_grid) {
    int num_rows = obstacle_grid.size();
    int num_cols = obstacle_grid[0].size();

    std::vector<int> prev_paths(num_cols, 0);
    prev_paths[0] = 1;
    for (int row = 0; row < num_rows; ++row) {
      std::vector<int> paths(num_cols);
      for (int col = 0; col < num_cols; ++col) {
        if (obstacle_grid[row][col] == 1) {
          continue;
        }
        if (col == 0) {
          paths[col] = prev_paths[col];
          continue;
        }
        paths[col] = prev_paths[col] + paths[col - 1];
      }
      prev_paths = std::move(paths);
    }
    return prev_paths.back();
  }
};
