class PathCache {
  std::vector<std::vector<int>> path_cache_;

 public:
  PathCache(int num_rows, int num_cols) {
    path_cache_ = std::vector(num_rows, std::vector<int>(num_cols, -1));
  }

  bool contains(int row, int col) { return path_cache_[row][col] != -1; }

  void set(int row, int col, int num) { path_cache_[row][col] = num; }

  int get(int row, int col) { return path_cache_[row][col]; }
};

class Solution {
  int find_unique_paths(int row, int col, PathCache& cache) {
    if (row == 0 || col == 0) {
      return 1;
    }
    if (cache.contains(row, col)) {
      return cache.get(row, col);
    }
    cache.set(row, col,
              find_unique_paths(row - 1, col, cache) +
                  find_unique_paths(row, col - 1, cache));
    return cache.get(row, col);
  }

 public:
  int uniquePaths(int m, int n) {
    PathCache cache(m, n);
    return find_unique_paths(m - 1, n - 1, cache);
  }
};
