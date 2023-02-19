//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n) {
    
        // Your code here
        if(n==1) return 1;
        long long prefix[n];
        int ans = -1;
        prefix[0] = a[0];
        for(int i = 1;i<n;i++) prefix[i] = prefix[i-1] + a[i];
          for(int i = 1;i<n;i++)
          if(prefix[i-1]==abs(prefix[n-1]-prefix[i]))
          
                 ans = i+1;
       return ans;
    }

};

//{ Driver Code Starts.


int main() {

    long long t;
    
    //taking testcases
    cin >> t;

    while (t--) {
        long long n;
        
        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        Solution ob;

        //calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends