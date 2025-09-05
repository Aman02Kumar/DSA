class Solution {
public:
    string frequencySort(string s){

        unordered_map<char,int> mp;
        for(auto i : s){
            mp[i]++;
        }
        
        priority_queue<pair<int,char>> pq;

        for(auto p : mp){
            pq.push({p.second,p.first});
        }

        string ans ;
        while(!pq.empty()){
            int cnt = pq.top().first;
            char ch = pq.top().second;
            pq.pop();

            ans.append(cnt,ch);
        }
        return ans;


    }
};
