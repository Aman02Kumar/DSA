class Solution {
public:
    int countPairs(vector<int>& n, int t) {
        
        int c = 0 ;
        sort(n.begin(),n.end());
        int l = 0 ;
        int r = n.size()-1;

        while(r>=l){
            if(n[l] + n[r] < t){
                c +=  r-l;
                l++;
            }else r--;

        }
        return c;
    }
};
