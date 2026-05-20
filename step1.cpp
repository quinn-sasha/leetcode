class Solution {
 public:
  int uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid) {
    int num_rows = obstacleGrid.size();
    int num_cols = obstacleGrid[0].size();
    std::vector<std::vector<int>> paths =
        std::vector(num_rows + 1, std::vector<int>(num_cols + 1, 0));
    paths[0][1] = 1;  // dummy path to set paths[1][1] = 1
    for (int row = 1; row <= num_rows; ++row) {
      for (int col = 1; col <= num_cols; ++col) {
        if (obstacleGrid[row - 1][col - 1] == 1) {
          paths[row][col] = 0;
          continue;
        }
        paths[row][col] = paths[row - 1][col] + paths[row][col - 1];
      }
    }
    return paths[num_rows][num_cols];
  }
};
