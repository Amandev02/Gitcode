//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int a[], int s)
    {
        //Moores Voting Algorithm
        int cnt = 0;
        int el; 
        
        for(int i = 0;i<s;i++){
            if(cnt==0){
                el = a[i];
                cnt++;
            }
            else if(el!=a[i]) cnt--;
            else cnt++;
        }
        int count  = 0;
         for(int i = 0;i<s;i++){
             if(el == a[i]) count++;
         }
        if(count>s/2) return el;
        return -1;
        // your code here
        
        
    }
};

//{ Driver Code Starts.

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}

// } Driver Code Ends