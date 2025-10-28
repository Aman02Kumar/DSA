class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        
        int e = 0;
        for(auto i : nums){
            if(i %2 ==0)e++;
        }
        int n =nums.size() ;
        vector <int> ans(n,1);

        
        while(e){
            ans[e-1] = 0;
            e--;
        }
        return ans;
    }
};