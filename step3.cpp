nclude <vector>

class Solution {
 public:
  int maxSubArray(std::vector<int>& nums) {
      int max_sum = nums[0];
      int prefix_sum = 0;
      for (int num : nums) {
            prefix_sum += num;
            max_sum = std::max(max_sum, prefix_sum);
            if (prefix_sum < 0) {
	            prefix_sum = 0;
	          }
          }
      return max_sum;
    }
};
