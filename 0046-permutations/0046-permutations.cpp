class Solution {
public:
    void rec(int ind,int n,vector<int>& nums, vector<vector<int>> &ans){
        if(ind==n){
            ans.push_back(nums);
            return;
        }
        
        for(int i = ind;i<nums.size();i++){
            swap(nums[ind],nums[i]);
            rec(ind+1,n,nums,ans);
            swap(nums[ind],nums[i]);
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        rec(0,nums.size(),nums,ans);
        return ans;
    }
};