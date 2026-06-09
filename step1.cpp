class Solution {
  struct DepthAndTotal {
    int depth;
    int total;  // total amount of money
  };

 public:
  int coinChange(std::vector<int>& coins, int amount) {
    if (amount == 0) {
      return 0;
    }
    std::vector<uint8_t> visited(amount, false);
    std::queue<DepthAndTotal> depth_and_total;
    depth_and_total.push({0, 0});
    while (!depth_and_total.empty()) {
      const auto [depth, total] = depth_and_total.front();
      depth_and_total.pop();
      for (int coin_value : coins) {
        int next_total = total + coin_value;
        if (next_total > amount) {
          continue;
        }
        if (next_total == amount) {
          return depth + 1;
        }
        if (!visited[next_total]) {
          visited[next_total] = true;
          depth_and_total.push({depth + 1, next_total});
        }
      }
    }
    return -1;
  }
};
