class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int t) {
        
        int i = 0;
        int sum = 0;
        int j = k;
        for(int p = 0 ; p <k ;p++){
            sum+=arr[p];
    
        }
        int ans = 0;
        if(sum/k >= t) ans++;

        while(j<arr.size()){
            sum+=arr[j];
            sum-=arr[i];
            if(sum/k >= t) ans++;
            j++;
            i++;
        }
        return ans;
    }
};