class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& arr) {
        
        map<int,int>mp;
        int n = arr.size();
        vector<int>ans;

        for(int i = 0 ; i<n;i++){
            if(mp[arr[i]] == 1) ans.push_back(arr[i]);
            mp[arr[i]]++;
            // if(mp[arr[i] == 1]) ans.push_back(arr[i])
        }
        return ans;
    }
};