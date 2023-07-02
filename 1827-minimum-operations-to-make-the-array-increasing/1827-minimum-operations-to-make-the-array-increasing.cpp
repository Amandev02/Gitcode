class Solution {
public:
    int minOperations(vector<int>& nums) {
        int cnt  = 0;
        int last = nums[0];
        for(int i = 1;i<nums.size();i++){
            if(nums[i]-last<=0) cnt += last-nums[i]+1;
          last = max(nums[i],last+1);    
            
        }
        return cnt;
    }
};