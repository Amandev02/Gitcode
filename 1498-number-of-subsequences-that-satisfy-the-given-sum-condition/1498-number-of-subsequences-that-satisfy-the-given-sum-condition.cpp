class Solution {
public:
    int mod = 1e9 + 7;
   
    int numSubseq(vector<int>& nums, int target) {

        sort(nums.begin(),nums.end());
        int ans = 0;
        int n = nums.size();
        vector<int> pow2(n+1);
        pow2[0] = 1;
        
        for(int i = 1;i<=n;i++)pow2[i] = (2*pow2[i-1])%mod;
        
        int i = 0,j =n-1;
        while(i<=j){
            
            if(nums[i]+nums[j]<=target){
                 ans = (ans + pow2[j-i])%mod;
                i++;
             
            }
            else j--;
        }
        return ans;
    }
};