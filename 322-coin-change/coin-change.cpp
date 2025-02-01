class Solution {
public:
    int find(vector<int> &coins, int t,vector<vector<int>> &dp, int ind){

        if(ind == 0 ){
            if(t%coins[0] ==0 ){
                return  t/coins[0];
            }
            else return 1e9;
        }
        if(dp[ind][t] != -1) return dp[ind][t];

        int np = find(coins,t,dp,ind-1);
        int p = 1e9;
        if(coins[ind] <=t){
            p = 1 + find(coins,t - coins[ind],dp,ind);
        }

        return dp[ind][t] = min(np , p);
    }
    int coinChange(vector<int>& coins, int t) {
        
        int n = coins.size();
        vector<vector<int>> dp(n+1,vector<int>(t+1,-1));
        int ans =  find(coins,t,dp,n-1);
         if(ans >= 1e9)
            return -1;
        return ans;
    }
};