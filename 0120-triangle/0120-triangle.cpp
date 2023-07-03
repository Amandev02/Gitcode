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
        
        vector<vector<int>> dp(m+1,vector<int>(m+1,-1));
        
        return rec(0,0,m,triangle,dp);
    }
};