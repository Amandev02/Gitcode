//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
     bool helper(int i,string s, set<string> &st, vector<int> &dp){
        if(i==s.length()) return true;
        if(dp[i]!=-1) return dp[i];
        string tmp = "";
        for(int j = i;j<s.length();j++){
            tmp += s[j];
            if((st.find(tmp)!=st.end()) && helper(j+1,s,st,dp)) return dp[i] = 1;
        }
        return dp[i] = 0;
    }
    
    int wordBreak(string s, vector<string> &wordDict) {
        //code here
         set<string> st(wordDict.begin(),wordDict.end());
        vector<int> dp(301,-1);
      return helper(0,s,st,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends