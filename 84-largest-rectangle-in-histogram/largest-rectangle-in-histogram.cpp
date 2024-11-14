class Solution {
public:

    vector<int> nse(vector<int>& arr){

            vector<int> ans(arr.size(),arr.size());
            stack<int> st;

            for(int i = arr.size()-1; i >= 0 ;i--){

                while(!st.empty() && arr[st.top()] >= arr[i]){
                    st.pop();
                }

                if(!st.empty()  ){
                    ans[i] = st.top();
                }

                st.push(i);
            }
            return ans;
    }
    

    vector<int> pse(vector<int>& arr){

            vector<int> ans2(arr.size(),-1);
            stack<int> st;

            for(int i =0; i < arr.size() ;i++){

                while(!st.empty() && arr[st.top()] >= arr[i]){
                    st.pop();
                }

                if(!st.empty()  ){
                    ans2[i] = st.top();
                }

                st.push(i);
            }
            return ans2;
    }
    int largestRectangleArea(vector<int>& arr) {

            int maxi = 0 ;
            vector<int> right = nse(arr);
            vector<int> left = pse(arr);

            for(int i = 0 ; i < arr.size() ; i++){
                    maxi =max(maxi , arr[i]*(right[i] - left[i] - 1 ));
            }
            return maxi;
    }
};