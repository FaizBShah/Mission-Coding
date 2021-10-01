//https://leetcode.com/problems/house-robber/

class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1,0);
        dp[0]=nums[0];
        if(n==1){
            return dp[0];
        }
        dp[1]=max(nums[1],nums[0]);
        for(int i=2;i<n;i++){
            int op1=dp[i-1];
            int op2=dp[i-2]+nums[i];
            dp[i]=max(op1,op2);
        }
        return dp[n-1];
        return 0;
    }
};
© 2021 GitHub, Inc.
Terms
