class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {

        vector<int> st;
        for(int i = 0 ; i < arr.size();i++){
            if(arr[i]> 0 ) {
                st.push_back(arr[i]);
            }
            else {
                    while(!st.empty() && st.back() > 0 && st.back()< abs(arr[i])){
                        st.pop_back();

                    }

                    if(!st.empty()  &&  st.back()== abs(arr[i])) {
                        st.pop_back();
                    }

                    else if(st.empty() || st.back() < 0){
                        st.push_back(arr[i]);
                    }
                }
        }
        // sort(st.begin(),st.end());
        return st;
    }
};