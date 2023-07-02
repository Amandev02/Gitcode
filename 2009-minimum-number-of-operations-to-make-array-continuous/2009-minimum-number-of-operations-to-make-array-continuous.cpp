class Solution {
public:
    int minOperations(vector<int>& nums) {
         sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int> different;
        different.push_back(nums[0]);
        for(int i=1;i<n;i++){
            if(nums[i]!=nums[i-1]){
                different.push_back(nums[i]);
            }
        }
        int i=0;
        int m=different.size();
        int ans=0;
        for(int j=0;j<m;j++){
            if(different[j]<=different[i]+n-1){
                ans=max(ans,j-i+1);
            }else{
                i++;
            }
        }
        return n-ans;
    }
};