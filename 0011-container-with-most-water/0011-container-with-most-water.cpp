class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size(),ans = -1e9;
        int  j= n-1,i = 0;
        
        while(j>i){
            
         if(height[i]<height[j]){
             ans = max(ans,(j-i)*(height[i]));
             i++;
         }
            else{
                 ans = max(ans,(j-i)*(height[j]));
             j--;
          
            }
        }
            
            return ans;
    }
};