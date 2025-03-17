class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int n=nums.size();
        if(n%2!=0) return false;
        unordered_map<int,int> m;
        for(auto x:nums) m[x]++;
        for(auto x:m) if((x.second)%2!=0) return false;
        return true;
    }
};