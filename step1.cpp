class Solution {
 public:
  int maxProfit(std::vector<int>& prices) {
    if (prices.size() == 1) {
      return 0;
    }
    int max_profit = 0;
    int lowest = prices[0];
    for (int price : prices) {
      max_profit = std::max(max_profit, price - lowest);
      lowest = std::min(lowest, price);
    }
    return max_profit;
  }
};
