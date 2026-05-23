#include <vector>

class Solution {
  int find_max_money(int start, int end, const std::vector<int>& nums) {
    int prev_robbed = 0;
    int prev_skipped = 0;
    for (int i = start; i < end; ++i) {
      int robbed = prev_skipped + nums[i];
      int skipped = std::max(prev_skipped, prev_robbed);
      prev_robbed = robbed;
      prev_skipped = skipped;
    }
    return std::max(prev_robbed, prev_skipped);
  }

 public:
  int rob(std::vector<int>& nums) {
    if (nums.size() == 1) {
      return nums.front();
    }
    int max_excluding_last = find_max_money(0, nums.size() - 1, nums);
    int max_excluding_first = find_max_money(1, nums.size(), nums);
    return std::max(max_excluding_last, max_excluding_first);
  }
};
