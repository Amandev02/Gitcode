class Solution {
public:
     int maxProfit(vector<int>& pr) {
      int mini = INT_MAX;
         int ans = 0;
        for(int i =0; i< pr.size() ; i++){
        mini = min(mini,pr[i]);
        ans = max(ans,pr[i]-mini);
    }
         return ans;
    return 0;
  }
};