class Solution {
public:
    int func(int start,int end,vector<int> arr){
        int prevmax = 0;
        int currmax = 0;
        
        for(int i = start;i<=end;i++){
            int temp = max(arr[i]+prevmax,currmax);
            prevmax = currmax;
            currmax = temp;
        }
        return currmax;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
         if(n==1) return nums[0];
        int ans1 = func(0,n-2,nums);
        int ans2 = func(1,n-1,nums);
        return max(ans1,ans2);
     
    }
};