class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int max_sum = nums[0];
        int prefix_sum = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (prefix_sum < 0) {
                prefix_sum = 0;
            }
            prefix_sum += nums[i];
            max_sum = std::max(max_sum, prefix_sum);
        }
        return max_sum;
    }
};
