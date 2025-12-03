
class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        int totParSides = 0 , curYParSides, totalTraps = 0 , mod = 1e9+7, possTraps, totYParSides;
        unordered_map<int,int> yf ;
        for(auto &p: points){
            curYParSides = yf[p[1]]++ ;
            totYParSides = (1ll*(curYParSides)*(curYParSides-1)/2)%mod ;
            possTraps = (1ll*(totParSides - totYParSides + mod)*curYParSides)%mod ; 
            totalTraps = (totalTraps + possTraps)%mod ;
            totParSides = (totParSides + curYParSides)%mod ;
        }
        return totalTraps ;
    }
};