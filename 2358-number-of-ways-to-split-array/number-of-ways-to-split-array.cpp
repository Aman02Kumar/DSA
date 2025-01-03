class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
       long int n=nums.size();
        vector<long int> pre(n),suf(n);
        pre[0]=nums[0];
        suf[n-1]=nums[n-1];
        for(long int i=1;i<n-1;i++){   
            pre[i]=nums[i]+pre[i-1];
            suf[n-i-1]=nums[n-i-1]+suf[n-i];
          
        }
        long int ans=0;
        for(long int i=0;i<n-1;i++){
            if(pre[i]>=suf[i+1])
            ans++;
        }
        return ans;
    }
};