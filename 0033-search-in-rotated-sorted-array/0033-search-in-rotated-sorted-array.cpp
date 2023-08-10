class Solution {
public:
    int search(vector<int>& arr, int target) {
        //find the sorted part nd search there
        int n = arr.size();
        int lo = 0,hi = n-1;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(arr[mid]==target) return mid;
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
        return -1;
    }
};