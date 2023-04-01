#include <bits/stdc++.h>

class Solution {
public:
    
    bool check(vector<int>& weights,int mid, int days){
        int cnt = 1,sum = 0;
        for(int i = 0;i<weights.size();i++){
            sum += weights[i];
            if(sum>mid){
                cnt++;
                sum = weights[i];
            }
        }
        if(cnt>days) return false;
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n= weights.size();
        int sum = 0;
        for(int i = 0;i<n;i++)
         sum += weights[i];
        int hi = sum;
        int lo = *max_element(weights.begin(),weights.end());
        int result, mid;
        while(lo<=hi){
            mid  = lo + (hi-lo)/2;
            if(check(weights,mid,days)){
                result = mid;
                hi = mid - 1;
            }
            else lo = mid + 1;
        }
       return result; 
    }
};