class Solution {
public:
    int seen =0;
    int res = 0;
    int countArrangement(int n,int pos = 1) {
    if(n<4) return n;
    if(pos>n) return res++;
    for(int i =1 ;i<=n;i++){
     int bit = 1<<i;
      if(!(bit&seen)&&(pos%i==0||i%pos==0)){
          seen^=bit;
          countArrangement(n,pos+1);
          seen^=bit;
      }
    } 
   return res;
       
    }
    
};