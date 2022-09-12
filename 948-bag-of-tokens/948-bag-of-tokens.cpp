class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
          if(tokens.size()<=0) return 0;
       if(power< *min_element(tokens.begin(),tokens.end())) return 0;
      
    
        int max_score = 0,score=0;
        
        sort(tokens.begin(),tokens.end());
        int i =0;
        int j = tokens.size()-1;
        while(i<=j){
            if(tokens[i]<=power){
                score++;
                power -= tokens[i++];
                 max_score=max(max_score,score);
            }
            else if(score>0){
                power += tokens[j--];
                    score--;
            }
             else break;
             
        }
        
        cout<<power<<" ";
        return max_score;
    }
};