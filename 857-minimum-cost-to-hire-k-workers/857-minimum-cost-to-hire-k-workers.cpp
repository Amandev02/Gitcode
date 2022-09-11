class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {    int n =quality.size(); 
        vector<pair<double,int>> cost(n);
     for(int i = 0;i<n;i++)
    cost[i] = {(double)(wage[i])/quality[i],quality[i]};
                                                                                 
    sort(cost.begin(),cost.end());
                                                                     
    priority_queue<int> pq;
    double res = 1e9, curr = 0;                                                      for(auto & [e,q]:cost){
       // cout<<e<<" "<<q<<"\n";
        curr+=q;
          pq.push(q);                                                              if(pq.size()>k){                                                                curr-=pq.top();
            pq.pop();                                                                           }
        if(pq.size()==k) res = min(res,curr*e);
                                                                                 }
                                                                                 return res;
                                                                                 
    }
};