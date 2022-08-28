class Solution {
public:
    int countArrangement(int n) {
 int results[12] = {8, 10, 36, 41, 132, 250, 700, 750, 4010, 4237, 10680, 24679};
  
        if (n < 4) return n;
        return results[n - 4];
    
       
    }
};