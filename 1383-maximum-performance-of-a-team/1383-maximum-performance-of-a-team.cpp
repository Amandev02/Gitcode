class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int,int>> cost(n);
        for(int i=0;i<n;i++)
            cost[i] = {efficiency[i],speed[i]};
        sort(rbegin(cost),rend(cost));
        
         priority_queue <int, vector<int>, greater<int>> pq; //min heap
        long long res = 0, ssum = 0;
        int mod = 1e9 +7;
        for(auto [e, s]:cost){
            ssum+=s;
            pq.push(s);
            if(pq.size()>k){
                ssum-= pq.top();
                pq.pop();
            }
            res = max(res,ssum * e);
        }
        return res%mod;
    }
};