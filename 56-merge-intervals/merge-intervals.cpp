class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        
        sort(arr.begin(),arr.end());

        vector<vector<int>> ans;

        for(auto x : arr){

            if(ans.empty() || ans.back()[1] < x[0]){
                ans.push_back(x);
            }
            else ans.back()[1] = max(ans.back()[1] , x[1]);
        }
        return ans;
    }
};