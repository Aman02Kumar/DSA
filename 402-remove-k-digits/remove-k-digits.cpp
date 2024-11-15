class Solution {
public:
    string removeKdigits(string num, int k) {
        
        stack<char> st;
        int  n = num.size();
      
        for(int i = 0 ;i < num.size() ; i++){

            while(!st.empty()  &&  k > 0 && (st.top() - '0' > num[i] -'0')){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while(k > 0 && !st.empty())     k--, st.pop();

        if(st.empty()) return "0";

        string res = "";
        while(!st.empty()){
            res += st.top();
            st.pop();
        }

        reverse(res.begin() , res.end() );

        // removing zeroes from anser
        int index = 0 ;
        while(index < res.size()  && res[index] =='0'){
            index++;

        }

        res = res.substr(index);
        return res.empty() ? "0" :res;

    }
};