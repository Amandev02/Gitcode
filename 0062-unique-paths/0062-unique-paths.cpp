class Solution {
public:
    int fun(int m,int n,vector<vector<int>> &dp){
        if(m<0 || n<0) return 0;
        if(m==0 && n==0) return 1;
        if(dp[m][n]!=-1) return dp[m][n];
                     //top + right
         int ans = fun(m-1,n,dp) + fun(m,n-1,dp);
        return dp[m][n] = ans;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return fun(m-1,n-1,dp);
    }
};