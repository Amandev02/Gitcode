//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    bool check(int mid, int A[], int N, int M){
        int sum = 0,cnt  = 1;
        
        for(int i = 0;i<N;i++){
            sum+=A[i];
       if(sum>mid){
            cnt++;
           sum = A[i];
       }
        
        }
        if(cnt<=M) return true;
        return false;
        
    }
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        //code here
          if(N<M)return -1;  

        int sum = 0;
        int lo = *max_element(A,A+N);
        for(int i = 0;i<N;i++) sum += A[i];
        int hi = sum;
        int res = -1;
        while(lo<=hi){
           int mid = lo + (hi - lo)/2;
            if(check(mid,A,N,M)){
                 hi = mid -1;
                 res = mid;
            }
            else lo = mid + 1;
            
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends