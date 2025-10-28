class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        
        set<int> s;
        for(auto i:allowed){
            s.insert(i);
        }
        int ans= 0;

        for(auto i : words){
            int x = 0;
            for(auto k : i){
                if(s.find(k) != s.end()){
                    x++;
                }

            }
            if(x == i.size()) ans++;
        }
        
        return ans;
    }
};