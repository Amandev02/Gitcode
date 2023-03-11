//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
   int rec(int r,int c, vector<vector<int>> &dp, vector<vector<int>> &M){
     //Base condition 
     int n = M.size(),m = M[0].size();
      if ((r== n) || (c == m))  return 0;
    
   
       if(dp[r][c]!=-1) return dp[r][c];
       
       int left_diag =0;
        if(r>0) left_diag = rec(r-1,c+1,dp,M);
       int right = rec(r,c+1,dp,M);
       int right_diag = rec(r+1,c+1,dp,M);
        return dp[r][c] = M[r][c] + max(max(left_diag,right_diag),right);
       
   }
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        // code here
         vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
         int maxgold = 0;
         for(int i =0;i<n;i++) maxgold = max(maxgold,rec(i,0,dp,M));
         
         return maxgold;
         
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}
// } Driver Code Ends