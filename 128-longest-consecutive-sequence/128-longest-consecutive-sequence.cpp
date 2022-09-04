class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
   unordered_set<int>  mp(begin(nums),end(nums));
        int res = 0;
        
        for(auto& num :mp){

            if(mp.count(num - 1)) continue;
              int ans =1;
		while(mp.count(num + ans)) ans++;
		res = max(ans, res);
        }
        return res;
    }
};