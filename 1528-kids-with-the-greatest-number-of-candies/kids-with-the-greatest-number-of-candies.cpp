class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& c, int ex) {
        if(c.size()==0) return {};
        int n = c.size();
        int m = *max_element(c.begin(),c.end());
        vector<bool> ans;
        for(auto i : c){
            if(i+ ex >= m){
                ans.push_back(true);
            }
            else ans.push_back(false);
        }
        return ans;
    }
};