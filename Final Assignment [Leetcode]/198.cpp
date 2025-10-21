class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        if (size == 0) return 0;
        if (size == 1) return nums[0];
        vector<int> maxMoney(size, 0);
        maxMoney[0] = nums[0];
        maxMoney[1] = max(nums[0], nums[1]);
        for (int i = 2; i < size; i++) {
            int robCurrent = nums[i] + maxMoney[i - 2];
            int skipCurrent = maxMoney[i - 1];
            maxMoney[i] = max(robCurrent, skipCurrent);
        }
        return maxMoney[size - 1];
    }
};
