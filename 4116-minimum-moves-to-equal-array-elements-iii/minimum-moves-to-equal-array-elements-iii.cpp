class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int max = INT_MIN;
        for (int i =0; i < n; i++) {
            if(nums[i] > max) {
                max = nums[i];
            }
        }
        int min_moves = 0;
        for (int i = 0; i < n; i++) {
            min_moves += abs(nums[i] - max);
        }
        return min_moves;
    }
};