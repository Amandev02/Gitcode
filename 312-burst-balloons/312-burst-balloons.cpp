class Solution {
public:
    //BEST SOLUTION tc-(On^3)
    int maxCoins(vector<int>& a) {
        int n = a.size();
    a.push_back(1);
    a.insert(a.begin(),1);
        //Remember this n+2 is imp so that it does not go out of bound
    vector<vector<int>> dp(n+2,vector<int>(n+2,0));
    
    for(int i = n; i>=1;i--){
        for(int j = 1;j<=n;j++){
            //base case
            if(i>j) continue;
       int mini = INT_MIN;
      for(int ind = i;ind<=j;ind++){
   int cost = a[i-1]*a[ind]*a[j+1] + dp[i][ind-1]+ dp[ind+1][j];
 mini = max(mini,cost);
}
   dp[i][j] = mini;
        }
    }
    return dp[1][n];
    
    }
};