//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    // Function to find
// rightmost index
// which satisfies the condition
// arr[j] - arr[i] <= k
   int func(int i,int j,int k, vector<int>& arr, vector<vector<int>> &dp){
        if(i>=j) return 0;
        if(arr[j]-arr[i] <=k) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
    
         return dp[i][j] = 1 + min(func(i+1,j,k,arr,dp),func(i,j-1,k,arr,dp));
         
        
        
    }
    int removals(vector<int>& arr, int k){
        //Code here
        sort(arr.begin(),arr.end());
        int n = arr.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        
       
        
        return func(0,n-1,k,arr,dp);
        
        
    }
};


//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        Solution ob;
        int ans = ob.removals(arr,k);
        
        cout<<ans<<endl;
    }
}



// } Driver Code Ends