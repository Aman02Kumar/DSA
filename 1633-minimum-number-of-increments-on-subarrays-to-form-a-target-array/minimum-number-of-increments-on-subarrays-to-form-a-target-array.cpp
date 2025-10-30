class Solution {
public:
    int minNumberOperations(vector<int>& t) {
        int o = t[0]; // start with first element
        
        for (int i = 1; i < t.size(); i++) {
            if (t[i] > t[i - 1]) {
                o += t[i] - t[i - 1];
            }
        }
        
        return o;
    }
};
