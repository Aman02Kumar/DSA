class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        
        vector<int> st;

        for(int x : arr){
            if(st.empty() || (st.back() > 0  && x > 0) ){
                st.push_back(x);
            } 
            else {
                while(!st.empty() && st.back() >0 && abs(x) > st.back()){
                    st.pop_back();
                }

                    if(!st.empty()  &&  st.back()== abs(x) ){
                        st.pop_back();
                    }

                    else if(st.empty() || st.back() < 0){
                        st.push_back(x);
                    }

            }
        }
        return st;
    }
};