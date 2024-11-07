class Solution {
public:
    long long subArrayRanges(vector<int>& arr) {
        
        long long sum = 0 ;
        
        for(int i = 0 ; i < arr.size();i++){

            int lar = arr[i] , smal = arr[i];
            for(int j = i+1 ; j < arr.size();j++){

                    lar = max(arr[j],lar);
                    smal = min (arr[j] , smal);

                    sum = sum + (lar - smal);

            }
        }
        return sum;
    }
};