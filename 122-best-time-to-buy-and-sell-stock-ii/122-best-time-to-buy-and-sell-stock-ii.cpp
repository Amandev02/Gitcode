#define ll long long
class Solution {
public:
    ll func(int ind,int buy,vector<int> prices,int n,vector<vector<ll>> &dp){
      if(ind==n) return 0;
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        ll profit = 0;
        if(buy){
            profit = max((-prices[ind] + func(ind+1,0,prices,n,dp)), func(ind+1,1,prices,n,dp));
        }
        else{
            profit = max(prices[ind] + func(ind+1,1,prices,n,dp), func(ind+1,0,prices,n,dp));
        }
        return dp[ind][buy] = profit;
    }
    
    ll maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<ll>> dp(n,vector<ll>(2,-1));
        // memset(dp,-1,sizeof(dp));
         
        for(int ind = n-1;ind>=0;ind--){
             ll profit = 0;
            for(int buy = 0;buy<=1 ;buy++){
                
     if(buy){
            profit = max((-prices[ind] + func(ind+1,0,prices,n,dp)), func(ind+1,1,prices,n,dp));
        }
        else{
            profit = max(prices[ind] + func(ind+1,1,prices,n,dp), func(ind+1,0,prices,n,dp));
        }
         dp[ind][buy] = profit;
            }
        }
        return dp[0][1];
    }
};