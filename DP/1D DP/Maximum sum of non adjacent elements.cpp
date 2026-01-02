class Solution {
public:
    int solve(int idx,vector<int>& nums,vector<int>& dp){
        if(idx==0) return nums[idx];
        if(idx<0) return 0;

        if(dp[idx]!=-1) return dp[idx];

        int pick = nums[idx] + solve(idx-2,nums,dp);
        int notPick = 0 + solve(idx-1,nums,dp);

        return dp[idx] = max(pick,notPick);
    }
    int nonAdjacent(vector<int>& nums) {
      int n = nums.size();
      vector<int> dp(n,-1);
      int ans = solve(n-1,nums,dp);
      return ans;
    }
};