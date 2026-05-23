#include <vector>

class Solution {
  int find_max_money(int start, int end, const std::vector<int>& nums) {
    int max_money = 0;
    int prev_skipped = 0;
    for (int i = start; i < end; ++i) {
      int robbed_here = prev_skipped + nums[i];
      prev_skipped = max_money;
      max_money = std::max(max_money, robbed_here);
    }
    return max_money;
  }

 public:
  int rob(std::vector<int>& nums) {
    if (nums.size() == 1) {
      return nums.front();
    }
    int max_without_last = find_max_money(0, nums.size() - 1, nums);
    int max_without_first = find_max_money(1, nums.size(), nums);
    return std::max(max_without_last, max_without_first);
  }
};
