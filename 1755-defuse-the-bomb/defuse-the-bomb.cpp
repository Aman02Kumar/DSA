class Solution {
public:
    vector<int> decrypt(vector<int>& nums, int k) {
        
        int n = nums.size();
        vector<int> result(n,0);
        if(k==0) return result;
        int i =-1,j=-1;
        if(k>0){
            i = 1 ;
            j = k;
        }
        else {
            i = n - abs(k);
            j = n -1;
        }


        int sum  = 0;
        for(int x =  i ; x<=j ; x++){
            sum += nums[x];
        }

        for(int l = 0 ; l < n;l++){
            result[l] = sum;

            sum -= nums[i%n];
            i++;

            sum += nums[(j+1) % n];
            j++;
        }
        return result;
    }
};