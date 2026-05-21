#include <vector>

class Solution {
 public:
  int rob(std::vector<int>& nums) {
    int prev_robbed = 0;
    int prev_skipped = 0;
    for (int num : nums) {
      int robbed = prev_skipped + num;
      prev_skipped = std::max(prev_skipped, prev_robbed);
      prev_robbed = robbed;
    }
    return std::max(prev_skipped, prev_robbed);
  }
};
