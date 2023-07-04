//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:

    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<int> prev(W+1,0),curr(W+1,0);
    //   vector<vector<int>> dp(n+1,vector<int>(W+1,0));
       for(int c = 0;c<=W;c++){
            if(wt[0]<=c) prev[c] = val[0];
       }
       
       for(int i =1;i<n;i++){
           for(int c = 0;c<=W;c++){
              
        int notPick = prev[c];
        int pick = 0;
         if(c>=wt[i]) pick = prev[c-wt[i]] + val[i];
         
          curr[c] = max(pick,notPick);
           
               
           }
           prev = curr;
       }
    //   return rec(n-1,W,wt,val,dp);
    return prev[W];
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends