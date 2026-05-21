class Solution {
 public:
  int rob(std::vector<int>& nums) {
    int max_money = nums[0];
    std::vector<int> robbed_moneys = nums;
    for (int i = 0; i < nums.size(); ++i) {
      for (int j = 0; j < i - 1; ++j) {
        int money = nums[i] + robbed_moneys[j];
        robbed_moneys[i] = std::max(robbed_moneys[i], money);
      }
      max_money = std::max(max_money, robbed_moneys[i]);
    }
    return max_money;
  }
};
