class Solution {
   public:
    int frogJump(vector<int>& heights, int k) {
        int n = heights.size();

        vector<int> dp(k,0);

        for (int i = 1; i < n; i++) {
            int minStep = INT_MAX;
            for (int j = 1; j <= k; j++) {
                if (i - j >= 0) {
                    int jump = dp[(i-j)%k] + abs(heights[i] - heights[i - j]);
                    minStep = min(minStep, jump);
                }
            }
            dp[i%k] = minStep;
        }

        return dp[(n-1)%k];
    }   `
};