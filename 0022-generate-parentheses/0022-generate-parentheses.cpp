class Solution {
public:
    void rec(int open,int close,int n,vector<string> &ans,string s){
        if(s.length()==2*n){
            ans.push_back(s);
            return;
        }
        
        if(open<n) rec(open+1,close,n,ans,s+"(");
        if(close<open) rec(open,close+1,n,ans,s+")");
        
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        rec(0,0,n,ans,"");
            return ans;
    }
};