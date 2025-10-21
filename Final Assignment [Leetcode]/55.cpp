class Solution {
public:
    bool canJump(vector<int>& nums) {
        int size = nums.size();
        vector<bool> canReach(size, false);
        canReach[0] = true; // we start from index 0
        for (int i = 0; i < size; i++) {
            if (canReach[i] == false) continue; // if we can’t reach this index, skip
            int maxJump = nums[i]; // how far we can jump from here
            for (int j = 1; j <= maxJump && i + j < size; j++) {
                canReach[i + j] = true; // mark next positions as reachable
            }
        }
        return canReach[size - 1]; // check if we can reach the last index
    }
};
