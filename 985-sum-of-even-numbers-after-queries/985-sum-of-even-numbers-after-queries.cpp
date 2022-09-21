#define all(v) v.begin(), v.end()
#define sumv(v) accumulate(all(v),0)
class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {   
    vector<int> ans;
        int sum=0;
        for(int i=0;i<nums.size();i++){
		//store the sum of even elements
            if(nums[i]%2==0){
                sum+=nums[i];
            }
        }
        for(auto it:queries){
		// if element stored in nums vector at given index in queries is even then 
		// subtract that element from the sum and if after updating the value of nums 
		// at given index, the value comes even then add that value to the sum.
            if(nums[it[1]]%2==0) sum-=nums[it[1]];
            nums[it[1]]=it[0]+nums[it[1]];
            if(nums[it[1]]%2==0){
                sum+=nums[it[1]];
            }
            ans.push_back(sum);
        }
        return ans;
    }
};