class Solution {
 public:
  int coinChange(std::vector<int>& coins, int target_amount) {
    const int kMaxNumCoins = std::numeric_limits<int>::max() / 2;
    std::vector<int> fewest_coins(target_amount + 1, kMaxNumCoins);
    fewest_coins[0] = 0;
    for (int amount = 1; amount <= target_amount; ++amount) {
      for (int coin : coins) {
        if (coin > amount) {
          continue;
        }
        fewest_coins[amount] =
            std::min(fewest_coins[amount], 1 + fewest_coins[amount - coin]);
      }
    }
    if (fewest_coins[target_amount] == kMaxNumCoins) {
      return -1;
    }
    return fewest_coins[target_amount];
  }
};
