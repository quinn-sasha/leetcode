class Solution {
 public:
  int maxProfit(std::vector<int>& prices) {
    std::vector<int> future_max_prices(prices.size());
    future_max_prices[prices.size() - 1] = prices.back();
    for (int i = prices.size() - 2; i >= 0; --i) {
      future_max_prices[i] = std::max(future_max_prices[i + 1], prices[i]);
    }
    int max_profit = 0;
    for (int i = 0; i < prices.size() - 1; ++i) {
      int profit = future_max_prices[i + 1] - prices[i];
      max_profit = std::max(max_profit, profit);
    }
    return max_profit;
  }
};
