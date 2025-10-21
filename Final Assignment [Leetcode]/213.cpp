class Solution {
public:
    int helper(vector<int>& nums, int i, int end, vector<int>& dp) {
        if (i > end) return 0;
        if (dp[i] != -1) return dp[i];
        int take = nums[i] + helper(nums, i + 2, end, dp);
        int skip = helper(nums, i + 1, end, dp);
        return dp[i] = max(take, skip);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        vector<int> dp1(n, -1), dp2(n, -1);
        int case1 = helper(nums, 0, n - 2, dp1); 
        int case2 = helper(nums, 1, n - 1, dp2);
        return max(case1, case2);
    }
};
