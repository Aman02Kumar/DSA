class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& d) {
        
        int n = d.size();
        double maxd = 0 ;
        int ans = 0;
        for(int i = 0 ; i < n ;i++){

            double dd = sqrt(( d[i][0] *d[i][0] )+ (d[i][1] *d[i][1] ));

            if(dd > maxd ){
                 maxd = max(dd,maxd);
                 ans = d[i][0] * d[i][1];
            }
            else if(dd == maxd){
                  ans = max(ans,d[i][0] * d[i][1]);
            }


        }
        return ans;
    }
};