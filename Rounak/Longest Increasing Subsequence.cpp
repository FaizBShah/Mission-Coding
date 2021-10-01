//https://leetcode.com/problems/longest-increasing-subsequence/

//O(N^2) DP solution
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1,0);
        dp[0]=1;
        for(int i=1;i<n;i++){
            dp[i]=0;
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    dp[i]=max(dp[i],dp[j]);
                }
            }
            dp[i]+=1;
        }
        int max_dp=0;
        for(int i=0;i<n;i++){
            max_dp=max(dp[i],max_dp);
        }
        return max_dp;
    }
};

//O(NlogN) DP solution
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> seq;
        seq.push_back(nums[0]);
        for(int i=1;i<n;i++){
            if(nums[i]>seq[seq.size()-1])
                seq.push_back(nums[i]);
            else{
                int pos=lower_bound(seq.begin(),seq.end(),nums[i])-seq.begin();
                seq[pos]=nums[i];
            }
        }
        return seq.size();
    }
};
