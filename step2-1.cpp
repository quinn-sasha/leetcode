nclude <vector>

class Solution {
 public:
  int uniquePaths(int m, int n) {
      std::vector<int> paths(n, 0);
      paths[0] = 1;
      for (int row = 0; row < m; ++row) {
            for (int col = 1; col < n; ++col) {
	            paths[col] += paths[col - 1];
	          }
          }
      return paths[n - 1];
    }
};
