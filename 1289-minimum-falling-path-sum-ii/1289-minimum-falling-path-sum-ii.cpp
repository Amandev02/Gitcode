class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        
         for(int i=0;i<n;i++)
             dp[0][i]=grid[0][i];
        
        
      for(int i=1;i<grid.size();i++){
            for(int j=0;j<grid.size();j++){
                int ans=INT_MAX;
                for(int k=0;k<grid.size();k++){
                    if(j==k) continue;
                    ans=min(ans,grid[i][j]+dp[i-1][k]);
                }
                dp[i][j]=ans;
            }
        }
        
        int res = INT_MAX;
        for(int i =0;i<n;i++)
        res = min(res,dp[n-1][i]);
        
        return res;
    }
};