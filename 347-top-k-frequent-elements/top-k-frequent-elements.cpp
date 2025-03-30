

class Solution {
public:
   
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        for(auto it:nums){
            mpp[it]++;
        }
        
      
       priority_queue< pair<int,int>,vector< pair<int,int>>,greater<pair<int,int>>> p;
       
       for(auto it:mpp){
         int value = it.first;
         int freq = it.second;
         p.push({freq,value});
         if(p.size()>k) p.pop();
       }

    vector<int> ans;
    while(!p.empty()){
        ans.push_back(p.top().second);
        p.pop();
    }

        return ans;
    }
};