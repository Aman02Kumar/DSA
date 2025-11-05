class Solution {
public:
    vector<int> decrypt(vector<int>& nums, int k) {
        
        int n = nums.size();
        vector<int> result(n);

        if(k==0){
            return vector<int>(n,0);
        }

        for(int i = 0 ; i < n;i++){
            int sum = 0 ;

            if(k>0){

                    for(int j = 1 ; j <= k ; j++){
                        sum += nums[(i+j)%n];
                    }
            }
            else{

                    for(int j = 1 ; j <= abs(k) ; j++){
                        sum += nums[(i-j + n )%n];
                    }
            }
            result[i] =sum;
        }
        return result;
    }
};