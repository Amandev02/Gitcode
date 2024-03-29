class Solution {
public:
    int rec(int ind,int amount, vector<int>& coins,vector<vector<int>> &dp){
        if(ind==0){
            if(amount%coins[0]==0) return 1;
            return 0;
        }
        if(dp[ind][amount]!=-1) return dp[ind][amount];
        //notpick
     
       int notpick = rec(ind-1,amount,coins,dp);
       int pick = 0;
       if(amount>=coins[ind]) pick = rec(ind,amount-coins[ind],coins,dp);
        return  dp[ind][amount] = (notpick + pick);
     
    }
    
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1,-1));
       return rec(n-1,amount,coins,dp);
    }
};