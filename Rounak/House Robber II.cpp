//https://leetcode.com/problems/house-robber-ii/

class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp1(n,0); 
        vector<int> dp2(n,0);
        if(n==1){
            return nums[0];
        }
        if(n==2){
            return max(nums[0],nums[1]);
        }
        //Excluding the last element and including the first element
        dp1[0]=nums[0];
        dp1[1]=max(nums[1],nums[0]);
        for(int i=2;i<n-1;i++){
            int op1=dp1[i-1];
            int op2=dp1[i-2]+nums[i];
            dp1[i]=max(op1,op2);
        }
        //Including the last element and excluding the first element
        dp2[1]=nums[1];
        dp2[2]=max(nums[2],nums[1]);
        for(int i=3;i<n;i++){
            int op1=dp2[i-1];
            int op2=dp2[i-2]+nums[i];
            dp2[i]=max(op1,op2);
        }
        return max(dp1[n-2],dp2[n-1]);
    }
};
