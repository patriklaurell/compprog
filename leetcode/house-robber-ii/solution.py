class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums) <= 3:
            return max(nums)

        dp = [-1 for i in range(len(nums)+1)]
        dp2 = [-1 for i in range(len(nums)+1)]

        v1 = nums[0] + self.dp_rob(nums[2:-1], dp)
        v2 = self.dp_rob(nums[1:], dp2)

        return max(v1,v2)
        
    def dp_rob(self, nums, dp):
        if len(nums) == 1:
            return nums[0]
        elif len(nums) == 2:
            return max(nums)

        if dp[len(nums)] != -1:
            return dp[len(nums)]
        else:
            dp[len(nums)] = max(nums[0] + self.dp_rob(nums[2:], dp), self.dp_rob(nums[1:], dp))
            return dp[len(nums)]
