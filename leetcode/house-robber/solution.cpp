class Solution {
public:
    vector<int> map;

    int rob(vector<int>& nums) {
        map.reserve(nums.size()+1);
        for (int i = 0; i < nums.size()+1 ; i++) {
            map[i] = -1;
        }

        return dp_rob(nums, 0);
    }

    int dp_rob(vector<int>& nums, int i) {
        if (i == nums.size()-1) {
            return nums[i];
        } else if (i == nums.size() - 2) {
            return max(nums[i], nums[i+1]);
        }

        if (map[i] != -1) {
            return map[i];
        } else {
            map[i] = max(nums[i] + dp_rob(nums, i+2), dp_rob(nums, i+1));
            return map[i];
        }
    }
};
