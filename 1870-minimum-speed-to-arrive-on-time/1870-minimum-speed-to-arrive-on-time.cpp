class Solution {
public:
    bool check(int mid,vector<int>& dist, double hour){
        double time = 0,i;
        for(i  =0 ; i<dist.size()-1;i++){
            time += dist[i]/mid;
            if(dist[i]%mid) time++;
        }
        time += 1.0*dist[i]/mid;
       
        return time <= hour;
       
        
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
       // if(ceil(hour)<dist.size()) return -1;
        int lo = 1;
        int hi = 1e9;
        while(hi>lo){
            int mid = lo + (hi-lo)/2;
            if(check(mid,dist,hour)) hi = mid;
            else lo = mid+1;
        }
       
        if(lo!=1e9) return lo;
        return -1;
        
    }
};