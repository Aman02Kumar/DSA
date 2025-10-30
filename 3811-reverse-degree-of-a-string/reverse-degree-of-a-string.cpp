class Solution {
public:
    int reverseDegree(string ss) {
        int s = 0;
        for(int i = 0 ; i<ss.size();i++){
            int x = 26 - (ss[i] - 'a');
            s+= x*(i+1);
        }
        return s;
    }
};



