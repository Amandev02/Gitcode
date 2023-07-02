class Solution {
public:
    
     int fun(int m,int n,vector<vector<int>> &dp,vector<vector<int>>& obs){
        if(m<0 || n<0) return 0;
         if(obs[m][n]==1) return 0;
        if(m==0 && n==0) return 1;
        if(dp[m][n]!=-1) return dp[m][n];
                     //top + right
         int ans = fun(m-1,n,dp,obs) + fun(m,n-1,dp,obs);
        return dp[m][n] = ans;
    }
  
    int uniquePathsWithObstacles(vector<vector<int>>& obs) {
        
        int m = obs.size();
        int n = obs[0].size();
         vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return fun(m-1,n-1,dp,obs);
    }
};