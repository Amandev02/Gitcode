class Solution {
public:
   int dp[51][51][51];
    int rec(int i1,int j1,int j2,int n, vector<vector<int>>& grid){
      
        int i2 = i1 + j1 - j2;
        if(i1>=n||j1>=n||j2>=n||i2>=n||grid[i1][j1]==-1||grid[i2][j2]==-1) return -1e8;
        //as both will reach simeltaneously it doesnt matter to put both condition 
        if(i1==n-1&&j1==n-1) return grid[i1][j1];
        
        if(dp[i1][j1][j2]!=-1) return dp[i1][j1][j2];
        
         int ans = grid[i1][j1];
         if(i1!=i2) ans+= grid[i2][j2];
        
        
        int cherry = max(rec(i1+1,j1,j2+1,n,grid),rec(i1+1,j1,j2,n,grid));
        cherry = max(cherry,rec(i1,j1+1,j2+1,n,grid));
        cherry = max(cherry,rec(i1,j1+1,j2,n,grid));
        
        return dp[i1][j1][j2] = ans+cherry;
        
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        memset(dp , -1 , sizeof(dp));
        
        
        return  max(0,rec(0,0,0,n,grid));
    }
};