class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        if(changed.size()%2) return {};
      
        vector<int> res;
        sort(changed.begin(),changed.end());
        map<int,int> mp;
         for(int i = 0;i<(int)changed.size();i++){
          
            mp[changed[i]]++;
        }
        for(int i = 0;i<(int)changed.size();i++){
            
            if(mp[changed[i]*2]!=0 && mp[changed[i]]!=0){   mp[changed[i]]--;
                mp[changed[i]*2]--;
           
               res.push_back(changed[i]);}
           
          // else break;
        }
        
       for(auto it : mp) if(it.second>=1) return {};
    return res;
    }
};