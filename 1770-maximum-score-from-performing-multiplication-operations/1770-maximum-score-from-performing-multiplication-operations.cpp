#include <bits/stdc++.h>

class Solution {
public:
   int n,m;
    int dp[1001][1001];
 
    int maximumScore(vector<int>& nums, vector<int>&  multipliers) {
        n = nums.size();
        m =  multipliers.size();
       for(int i = 0;i<1001;i++){
           for(int j = 0;j<1001;j++)
               dp[i][j]=-1e6;
       }
        return func(0,0,nums, multipliers);
    }
       int func (int i,int j,vector<int>& nums, vector<int>& multipliers){
        if(j==m) return 0;
        if(dp[i][j]!=-1e6) return dp[i][j];
        int left = func(i+1,j+1,nums, multipliers) + nums[i]* multipliers[j];
        int right = func(i,j+1,nums, multipliers) + nums[n-1-(j-i)]* multipliers[j];
        return dp[i][j] = max(left,right);
    }
};