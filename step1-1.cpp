class Solution {
  int count_unique_paths(int row, int col, int max_row, int max_col) {
      if (row >= max_row) {
            return 0;
          }
      if (col >= max_col) {
            return 0;
          }
      if (row == max_row - 1 && col == max_col - 1) {
            return 1;
          }
      return count_unique_paths(row + 1, col, max_row, max_col) +
             count_unique_paths(row, col + 1, max_row, max_col);
    }

 public:
  int uniquePaths(int m, int n) { 
     return count_unique_paths(0, 0, m, n); 
    }
};
