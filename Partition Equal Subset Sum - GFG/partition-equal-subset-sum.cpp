//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
   int rec(int i, int sum,vector<vector<int>> &dp,int arr[]){
       if(sum==0) return 1;
       if(i==0) return arr[i]==sum;
       if(dp[i][sum]!=-1) return dp[i][sum];
       
       int notPick = rec(i-1,sum,dp,arr);
       int pick = 0;
       if(sum>=arr[i]) pick = rec(i-1,sum-arr[i],dp,arr);
       return dp[i][sum] = pick || notPick;
   }
    int equalPartition(int N, int arr[])
    {
        // code here
         int sum = 0;
        for(int i= 0;i<N;i++) sum+= arr[i];
        if(sum&1) return 0;
        sum = sum>>1;

        vector<vector<int>> dp(N,vector<int>(sum+1,-1));
        return rec(N-1,sum,dp,arr);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends