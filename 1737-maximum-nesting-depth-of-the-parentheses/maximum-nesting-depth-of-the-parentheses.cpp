class Solution {
public:
    int maxDepth(string s) {
        int curr_nes = 0, max_nes = 0, i = 0;
        while(i < s.length()){
            if(s[i] == '('){
                curr_nes++;
            }else if(s[i] == ')'){
                curr_nes--;
                }
                i++;
                max_nes = max(curr_nes, max_nes);
            }
        return max_nes;
    }
};