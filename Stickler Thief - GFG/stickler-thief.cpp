//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int func(int i,int arr[], vector<int> &dp){
        if(i<0) return 0;
        if(i==0) return arr[0];
        if(i==1) return max(arr[0],arr[1]);
        if(dp[i]!=-1) return dp[i];
        int pick = INT_MIN;
        if(i>1) pick = func(i-2,arr,dp) + arr[i];
        int notPick = func(i-1,arr,dp);
        return dp[i] = max(pick,notPick);
        
        
    }
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
      vector<int> dp(n+1,-1);
      
      int prev2 = 0; 
      int prev = arr[0];
      int curr;
      for(int i = 1;i<n;i++){
           int pick = prev2 + arr[i];
          int notPick = prev;
          curr = max(pick,notPick);
          prev2 = prev;
          prev = curr;
      }
   
      return prev;
      
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
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends