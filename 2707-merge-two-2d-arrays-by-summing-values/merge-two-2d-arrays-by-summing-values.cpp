class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& a, vector<vector<int>>& b) {
        vector<vector<int>> ans;
        int n = a.size();
        int m = b.size();
        int i = 0 , j = 0;

        while(i<n && j<m){
            vector<int> c; 
            if(a[i][0] == b[j][0]){
                c.push_back(a[i][0]);
                c.push_back(a[i][1] + b[j][1]);
                i++;
                j++;
                ans.push_back(c);
            }
            else if(a[i][0] < b[j][0]){
                ans.push_back(a[i]);
                i++;
            }
            else if(a[i][0] > b[j][0]){
                    ans.push_back(b[j]);
                    j++;
            }
        }

        while(i<n){
            ans.push_back(a[i]);
            i++;
        }
        
        while(j<m){
            ans.push_back(b[j]);
            j++;
        }

        return ans;
    }
};