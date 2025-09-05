class Solution {
public:
    int func(vector<int>nums){
         int n=nums.size();
        stack<int>st; int maxi=0;
        for(int i=0;i<nums.size();i++){
            while(!st.empty() && nums[st.top()]>nums[i]){
                int el=st.top(); st.pop();
                int nse=i; 
                int pse= st.empty() ? -1 : st.top();
                maxi=max(maxi,(nse-pse-1)*nums[el]);
            }
            st.push(i);
        }
        while(!st.empty()){
            int nse=n;
            int el=st.top() ; st.pop();
            int pse= st.empty() ? -1 : st.top();
            maxi=max(maxi,(nse-pse-1)*nums[el]);
        }
        return maxi;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size(); // rows 4 
        int m=matrix[0].size();  // 5
        int maxi=0;
        vector<int>psum(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='0') psum[j]=0;
                else{ psum[j]+=1;}
            }
            maxi=max(maxi,func(psum));
        }
        return maxi;
    }
};