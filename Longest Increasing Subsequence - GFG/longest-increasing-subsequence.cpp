//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int arr[])
    {
       // your code here
       vector<int> lis;
int insertedat[n];
for (int i = 0; i < n; ++i)
{
  if(lis.empty()||lis.back()<arr[i]){
    lis.push_back(arr[i]);
    insertedat[i] = lis.size();
  }
  else{
    //find the first element greater than equal to and replace it
    auto it = lower_bound(lis.begin(), lis.end(),arr[i]);
    *it = arr[i];
    insertedat[i] = it-lis.begin()+1;
  }
}
//gives u length of LIS
// cout<<lis.size()<<endl;
 return (int)lis.size();
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends