//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        // code here 
        stack<string> st;
        string s = "";
        for(int i = 0;i<S.length();i++){
            if(S[i]=='.') {
                st.push(s);
                s = "";
            }
            else s += S[i];
        }
        if(s!="") st.push(s);
    string ans = "";
    while(!st.empty()){
        string t = st.top();
        ans+= t;
        ans+=".";
        st.pop();
    }
    return ans.substr(0,ans.length()-1);
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends