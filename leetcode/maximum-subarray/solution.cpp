class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int min_prefix_sum = 0;
        int max_subarray_sum = std::numeric_limits<int>::min();

        int cumsum = 0;
        for (int i = 0 ; i < nums.size() ; i++) {
            cumsum += nums[i];
            max_subarray_sum = max(max_subarray_sum, cumsum - min_prefix_sum);
            min_prefix_sum = min(min_prefix_sum, cumsum);
        }

        return max_subarray_sum;
    }
};
