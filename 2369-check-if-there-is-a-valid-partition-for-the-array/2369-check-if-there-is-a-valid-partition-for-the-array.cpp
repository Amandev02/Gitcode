class Solution {
public:
    bool validPartition(vector<int>& nums) {
           vector<bool> dp( nums.size()+1, false);
        dp[0] = true;
        for( int i=2 ; i<nums.size()+1 ; i++){
            if( nums[i-1] == nums[i-2] && dp[i-2] ) dp[i] = true;
            if( i > 2 && dp[i-3] && (( nums[i-1] == nums[i-2] && nums[i-1] == nums[i-3]) || ( nums[i-1] == nums[i-2]+1 && nums[i-2] == nums[i-3]+1) ) ) dp[i] = true;
        }
        return *(dp.end()-1);
    
    }
};