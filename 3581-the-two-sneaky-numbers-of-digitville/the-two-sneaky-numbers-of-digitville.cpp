class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        
        map<int,int> mp ;
        vector<int>ans;
        for(auto i : nums){
            if(mp.find(i) != mp.end()){
                ans.push_back(i);
            }
            mp[i]++;
        }
        return ans;
    }
};