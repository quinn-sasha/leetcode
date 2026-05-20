class Solution {
  using Grid = std::vector<std::vector<int>>;

 public:
  int uniquePathsWithObstacles(Grid& obstacle_grid) {
    int num_rows = obstacle_grid.size();
    int num_cols = obstacle_grid[0].size();
    Grid num_paths = std::vector(num_rows, std::vector<int>(num_cols, -1));
    num_paths[num_rows - 1][num_cols - 1] = 1;
    return find_unique_paths(0, 0, obstacle_grid, num_paths);
  }

 private:
  int find_unique_paths(int row, int col, const Grid& obstacle_grid,
                        Grid& num_paths) {
    int num_rows = obstacle_grid.size();
    int num_cols = obstacle_grid[0].size();
    if (row >= num_rows || col >= num_cols) {
      return 0;
    }
    if (obstacle_grid[row][col] == 1) {
      num_paths[row][col] = 0;
      return 0;
    }
    if (num_paths[row][col] != -1) {
      return num_paths[row][col];
    }
    num_paths[row][col] =
        find_unique_paths(row + 1, col, obstacle_grid, num_paths) +
        find_unique_paths(row, col + 1, obstacle_grid, num_paths);
    return num_paths[row][col];
  }
};
