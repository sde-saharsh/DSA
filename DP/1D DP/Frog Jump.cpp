class Solution {
   public:
    int frogJump(vector<int>& heights) {
        int n = heights.size();
        vector<int> dp(n, -1);
        dp[0] = 0;

        for (int idx = 1; idx < n; idx++) {
            int fs = dp[idx - 1] + abs(heights[idx] - heights[idx - 1]);
            int ss = INT_MAX;
            if (idx > 1) {
                ss = dp[idx - 2] + abs(heights[idx] - heights[idx - 2]);
            }

            dp[idx] = min(fs, ss);
        }
        return dp[n - 1];
    }
};