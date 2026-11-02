class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int total_moves = 0;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int mid = nums[n / 2];
        for (int i = 0; i < n; i++){
            total_moves += abs(nums[i] - mid);
        }

        return total_moves;
    }
};