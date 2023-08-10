class Solution {
public:
    bool search(vector<int>& arr, int target) {
           int n = arr.size();
        int lo = 0,hi = n-1;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(arr[mid]==target) return 1;
            if(arr[mid]==arr[lo]&&arr[mid]==arr[hi]){
                lo++,hi--;
                continue;
            }
            //left sorted
            if(arr[lo]<=arr[mid]){
                if(arr[lo]<=target&&arr[mid]>=target) hi = mid -1;
                else lo = mid + 1;
            }
            //right sorted
            else{
                if(arr[hi]>=target &&arr[mid]<=target) lo = mid +1;
                else hi = mid - 1;
            }
        }
        return 0;
    }
};