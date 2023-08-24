//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int check(int i,int n,int m){
	    long long num = 1LL;
	    for(int j = 1;j<=n;j++){
	        num *= i;
	        if(num>m) return 2;
	    }
	    if(num==m) return 1;
	    return 0;
	}
	int NthRoot(int n, int m)
	{
	    // Code here.
	    int lo = 1,hi = m,ans = -1;
	    while(lo<=hi){
	        int mid = lo + (hi - lo)/2;
	        if(check(mid,n,m)==1) return mid;
	        else if(check(mid,n,m)==0) lo = mid + 1;
	        else hi = mid-1;
	    }
	   // int num = 1LL;
	   //   for(int j = 1;j<=n;j++){
	   //      num *= ans;
	   // }
	   // cout<<num;
	   // if(num!=m) return -1;
	    return -1;
	}  
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends