//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
class Solution{
    public:
        //Function to merge the arrays.
        void merge(long long A[], long long B[], int n, int m) 
        { 
            // code here 
        long long i = 0,j = 0, k = 0;
        long long C[m+n];
	while(i<n && j<m){
	if(A[i]<B[j]) C[k++] = A[i++];
	else C[k++] = B[j++];
	}

	while(i<n) C[k++] = A[i++];
	while(j<m) C[k++] = B[j++];
 for(int i = 0;i<m+n;i++){
     
     if(i<n) A[i] = C[i];
     else B[i-n] = C[i];
 }
        } 
};

//{ Driver Code Starts.

int main() 
{ 
	
	int T;
	cin >> T;
	
	while(T--){
	    int n, m;
	    cin >> n >> m;
	    
	    long long arr1[n], arr2[m];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    ob.merge(arr1, arr2, n, m); 

        for (int i = 0; i < n; i++) 
            cout<<arr1[i]<<" "; 
        
       
	    for (int i = 0; i < m; i++) 
		    cout<<arr2[i]<<" "; 
	    
	    cout<<endl;
	}

	return 0; 
} 

// } Driver Code Ends