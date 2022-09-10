class Solution {
public:
    int func(int ind, int buy ,int cap,vector<int> &prices,int n,int dp[n+1][2][3]){
        if(ind== n || cap==0) return 0;
        if(dp[ind][buy][cap]!=-1) return dp[ind][buy][cap];
        if(buy==1){
            return dp[ind][buy][cap] = max(-prices[ind] +func(ind+1,0,cap,prices,n,dp), func(ind+1,1,cap,prices,n,dp) );
        }
        
        return dp[ind][buy][cap] = max(prices[ind] + func(ind+1,1,cap-1,prices,n,dp), func(ind+1,0,cap,prices,n,dp));
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int dp[n+1][2][3];
        memset(dp,-1,sizeof(dp));
        return func(0,1,2,prices,n,dp);
    }
};