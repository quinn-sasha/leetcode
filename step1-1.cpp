#include <vector>

class Solution {
 public:
  int maxSubArray(std::vector<int>& nums) {
    std::vector<int> prefix_sums(nums.size());
    prefix_sums[0] = nums[0];
    int max_sum = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
      prefix_sums[i] = prefix_sums[i - 1] + nums[i];
      max_sum = std::max(max_sum, prefix_sums[i]);
      for (int j = 0; j < i; ++j) {
        max_sum = std::max(max_sum, prefix_sums[i] - prefix_sums[j]);
      }
    }
    return max_sum;
  }
};
