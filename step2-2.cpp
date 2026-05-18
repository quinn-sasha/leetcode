class Solution {
  int find_max_sum_containing_mid(int left, int mid, int right,
		                                    const std::vector<int>& nums) {
      int leftward_max_sum = nums[mid];
      int leftward_sum = 0;
      for (int i = mid; i >= left; --i) {
            leftward_sum += nums[i];
            leftward_max_sum = std::max(leftward_max_sum, leftward_sum);
          }
      int rightward_max_sum = nums[mid + 1];
      int rightward_sum = 0;
      for (int i = mid + 1; i <= right; ++i) {
            rightward_sum += nums[i];
            rightward_max_sum = std::max(rightward_max_sum, rightward_sum);
          }
      return leftward_max_sum + rightward_max_sum;
    }

  int find_max_sum(int left, int right, const std::vector<int>& nums) {
      if (left == right) {
            return nums[left];
          }
      int mid = left + (right - left) / 2;
      int left_max = find_max_sum(left, mid, nums);
      int right_max = find_max_sum(mid + 1, right, nums);
      int mid_max = find_max_sum_containing_mid(left, mid, right, nums);
      return std::max({left_max, right_max, mid_max});
    }

 public:
  int maxSubArray(std::vector<int>& nums) {
      return find_max_sum(0, nums.size() - 1, nums);
    }
};
