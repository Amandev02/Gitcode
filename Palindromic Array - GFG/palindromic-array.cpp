//{ Driver Code Starts
#include<iostream>
#include<string.h>
using namespace std;


// } Driver Code Ends
/*Complete the function below*/

class Solution {
public:
  
  int PalinNum(int a){
      int x = a;
      int y = 0;
      while(x>0){
            y = y * 10 + x % 10;
        x /= 10;
      }
      if(y==a) return 1;
      else return 0;
  }
    int PalinArray(int a[], int n)
    {
    	// code here
    	for(int i = 0;i<n;i++){
    	  if(!PalinNum(a[i])) return 0;
    	   
    	}
    	return 1;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i = 0; i < n; i++)
			cin>>a[i];
		Solution obj;
		cout<<obj.PalinArray(a,n)<<endl;
	}
}
// } Driver Code Ends