class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& arr) {
        int i = 0 ;
        int n = arr.size();
        int j = n -1 ;
        while(j>=i){

            if(arr[i] %2==0){
                i++;
            }

            else if(arr[j] % 2 == 0){
                swap(arr[i],arr[j]);
                j--;
                i++;
            }
            else {
                j--;
            }
        }
        return arr;
    }
};