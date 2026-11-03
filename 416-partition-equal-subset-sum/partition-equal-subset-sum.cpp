
class Solution {
public:
    int dp(int idx, int target, int n,
           vector<int>& nums,
           vector<vector<int>>& memo) {

        if (target == 0) return true;

        if (idx == n) return false;

        if (memo[idx][target] != -1) {
            return memo[idx][target];
        }

        bool take = false;

        if (nums[idx] <= target) {
            take = dp(idx + 1, target - nums[idx], n, nums, memo);
        }

        bool notTake = dp(idx + 1, target, n, nums, memo);

        return memo[idx][target] = take || notTake;
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int sum = 0;

        for (int x : nums) {
            sum += x;
        }

        if (sum % 2 != 0) return false;

        int target = sum / 2;

        vector<vector<int>> memo(n, vector<int>(target + 1, -1));

        return dp(0, target, n, nums, memo);
    }
};
