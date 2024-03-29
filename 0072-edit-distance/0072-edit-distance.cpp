class Solution {
public:
    int minDistance(string w1, string w2) {
        
        int n = w1.length(), m = w2.length();
        if(n==0) return m;
        if(m==0) return n;
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        
        for(int i = 1 ;i<=n;i++) dp[i][0] = i;
         for(int i = 1 ;i<=m;i++) dp[0][i] = i;
        
        for(int i = 1;i<=n;i++){
            for(int j =1;j<=m;j++){
               if(w1[i-1]!=w2[j-1]) dp[i][j] = min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1])) + 1;
                else dp[i][j] = dp[i-1][j-1];
            }
        }
        return dp[n][m];
    }
};