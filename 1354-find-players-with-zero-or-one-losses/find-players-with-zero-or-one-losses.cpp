class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> lost;
        
        for(auto it : matches) {
            int lose = it[1];
            lost[lose]++;
        }
        
        vector<int> notLost;
        vector<int> oneLos;
        
        for(auto it : matches) {
            int lose = it[1];
            int win  = it[0];
            
            if(lost[lose] == 1) {
                oneLos.push_back(lose);
            }
            if(lost.find(win) == lost.end()) {
                notLost.push_back(win);
                lost[win] = 2;
            }
            
        }
        
        // sort(begin(notLost), end(notLost));
        sort(notLost.begin(),notLost.end());
        // sort(begin(oneLos), end(oneLos));
        sort(oneLos.begin(),oneLos.end());
        
        return {notLost, oneLos};
    }
};