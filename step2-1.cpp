class Solution {
 public:
  int coinChange(std::vector<int>& coins, int amount) {
    std::vector<int> num_coins(amount + 1, amount + 1);
    num_coins[0] = 0;
    for (int i = 1; i <= amount; ++i) {
      for (int coin_value : coins) {
        int remain = i - coin_value;
        if (remain < 0) {
          continue;
        }
        num_coins[i] = std::min(num_coins[i], 1 + num_coins[remain]);
      }
    }
    if (num_coins[amount] == amount + 1) {
      return -1;
    }
    return num_coins[amount];
  }
};
