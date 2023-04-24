class Solution {
public:
    int mod = 1e9+7;
   int dp[102][102][102];
    int func(int i, int j, int k, int n, int minProfit, vector<int>& group, vector<int>& profit){
      //dp[i][j][k] = profit j when ith group is taken 
        if(k==profit.size()){
            if(j>=minProfit and n>=i) return 1;
            return 0;
        }
        else if(n<i) return 0;
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        int pick = 0, notpick = 0;
         notpick = func(i,j,k+1,n,minProfit,group,profit);
        pick = func(i+group[k],min(minProfit,j+profit[k]),k+1,n,minProfit,group,profit);
        return dp[i][j][k] = (pick%mod + notpick%mod)%mod;
        
    }
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
    
        memset(dp,-1,sizeof(dp));
      return  func(0,0,0,n,minProfit,group,profit);
        
        
    }
};