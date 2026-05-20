class Solution {
  using Grid = std::vector<std::vector<int>>;

 public:
  int uniquePathsWithObstacles(const Grid& obstacle_grid) {
    int num_rows = obstacle_grid.size();
    int num_cols = obstacle_grid[0].size();

    Grid num_paths = std::vector(num_rows + 1, std::vector<int>(num_cols + 1));
    num_paths[0][1] = 1;  // dummy path to set num_paths[0][0] = 1
    for (int row = 1; row <= num_rows; ++row) {
      for (int col = 1; col <= num_cols; ++col) {
        if (obstacle_grid[row - 1][col - 1] == 1) {
          continue;
        }
        num_paths[row][col] = num_paths[row - 1][col] + num_paths[row][col - 1];
      }
    }
    return num_paths[num_rows][num_cols];
  }
};
