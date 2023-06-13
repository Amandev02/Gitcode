class Solution {
public:
    bool check(int mid,vector<int>& dist, double hour){
        double time = 0;
        int i = 0;
        for(;i<dist.size()-1;i++)
        {
            time+= dist[i]/mid;
            if(dist[i]%mid)
            {
                time++;
            }
        }
        time += 1.0*dist[i]/mid;
        if(time <= hour)
        {
            return true;
        }
        return false;
        
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        if(ceil(hour)<dist.size()) return -1;
        int lo = 1;
        int hi = 1e9;
        while(hi>lo){
            int mid = lo + (hi-lo)/2;
            if(check(mid,dist,hour)) hi = mid;
            else lo = mid+1;
        }
       
        if(lo>0) return lo;
        return -1;
        
    }
};