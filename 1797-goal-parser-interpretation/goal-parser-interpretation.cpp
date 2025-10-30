class Solution {
public:
    string interpret(string ss) {
        string ans = "";
        for(int i = 0 ; i < ss.size();i++){

            if(ss[i] == 'G'){
                ans.push_back('G');
            }
            else if(ss[i] == '(' && ss[i+1] == ')'){
                i++;
                ans.push_back('o');
            }
            else {
                i +=3;
                ans.push_back('a');
                 ans.push_back('l');
            }

        }
        return ans;
    }
};