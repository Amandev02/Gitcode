class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int> nums) {
        int i = 0;
        int n = nums.size();
        while(i<n){
            int c = nums[i] - 1;
            if(nums[i]!=nums[c]) swap(nums[i],nums[c]);
            else i++;
        }
        vector<int> ans;
        for(int i = 0;i<n;i++){
            // cout<<nums[i]<<" ";
            if(nums[i]!=i+1) ans.push_back(i+1);
        }
        return ans;
    }
};