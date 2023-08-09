class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int i = 0;
        while(i<nums.size()){
             int c = nums[i];
            if(nums[i]<nums.size() && nums[i]!=nums[nums[i]]) swap(nums[nums[i]],nums[i]);
            else i++;
        }
        for( i = 0;i<nums.size();i++){
            if(nums[i]!=i) return i;
        }
        return nums.size();
        
    }
};