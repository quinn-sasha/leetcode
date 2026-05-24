class Solution {
 public:
  int maxProfit(std::vector<int>& prices) {
    int max_profit = 0;
    int future_max_price = prices.back();
    for (int i = prices.size() - 2; i >= 0; --i) {
      future_max_price = std::max(future_max_price, prices[i + 1]);
      int profit = future_max_price - prices[i];
      if (profit > 0) {
        max_profit += profit;
        future_max_price = prices[i];
      }
    }
    return max_profit;
  }
};
