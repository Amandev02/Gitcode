class Solution {
public:
    int rec(int i,int j,int n,vector<vector<int>>& triangle,vector<vector<int>>& dp){
        if(i==n-1) return triangle[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        
        int left = rec(i+1,j,n,triangle,dp) + triangle[i][j];
        int right = rec(i+1,j+1,n,triangle,dp) + triangle[i][j];
        
        return dp[i][j] = min(left,right);
        
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int m = triangle.size();
        
        vector<vector<int>> dp(m,vector<int>(m,0));
        
        for(int r = 0;r<m;r++)  dp[m-1][r] = triangle[m-1][r];
        
        dp[0][0] = triangle[0][0];
        for(int i = m-2;i>=0;i--){
            for(int j = i;j>=0;j--){
                
                int up = triangle[i][j] + dp[i+1][j];
				int up_left = triangle[i][j] + dp[i+1][j+1];
				dp[i][j] = min(up, up_left);
                
            }
        }
        
        return dp[0][0];
    }
};