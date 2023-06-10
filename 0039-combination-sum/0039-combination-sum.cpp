class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int>&candidates,int target,vector<int>&v,int i){
        if(i==candidates.size() || target<0){
            return;
        }
        if(target==0){
            ans.push_back(v);
            return;
        }
        // take
       if(candidates[i]<=target){
            v.push_back(candidates[i]);
            solve(candidates,target-candidates[i],v,i);
            v.pop_back();
        }
        // not take
       solve(candidates,target,v,i+1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>v;
        solve(candidates,target,v,0);
        return ans;
    }
};