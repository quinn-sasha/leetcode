#include <vector>

class Solution {
 public:
  int rob(std::vector<int>& nums) {
    int max_money = 0;
    int prev_not_robbed_max = 0;
    for (int num : nums) {
      int robbed = prev_not_robbed_max + num;
      prev_not_robbed_max = max_money;
      max_money = std::max(max_money, robbed);
    }
    return max_money;
  }
};
