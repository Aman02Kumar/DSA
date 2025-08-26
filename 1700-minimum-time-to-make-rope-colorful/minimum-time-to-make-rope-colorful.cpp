class Solution {
public:
    int minCost(string c, vector<int>& arr) {
        
        int prev = 0 ; 
        int time = 0 ;

        for(int i = 0 ;i < arr.size();i++){

            int curr = arr[i];
            if(i>0 && c[i] != c[i-1]){
                prev = 0;
            }
        
            time += min(prev,curr);
            prev = max(curr,prev);

        }
        return time;
    }
};