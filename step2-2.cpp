// top と bottom の差をとる解法
class Solution {
 public:
  int maxProfit(std::vector<int>& prices) {
    int max_profit = 0;
    for (int i = 0; i < prices.size(); ++i) {
      while (i < prices.size() - 1 && prices[i] >= prices[i + 1]) {
        i++;
      }
      int bottom = prices[i];
      while (i < prices.size() - 1 && prices[i] <= prices[i + 1]) {
        i++;
      }
      int top = prices[i];
      max_profit += top - bottom;
    }
    return max_profit;
  }
};
