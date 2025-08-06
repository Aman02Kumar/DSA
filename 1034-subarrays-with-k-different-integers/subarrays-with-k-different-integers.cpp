class Solution {
public:

     int atmost(vector<int>& nums,int k){

        int i=0;
        int j=0;
        int count =0;
        int n = nums.size();
        int sum =0;
        map<int,int> m;

        while( j < n){
            m[nums[j]]++;

            if(m.size() >= k){
                while(m.size() > k){
                    m[nums[i]]--;
                    if(m[nums[i]] == 0){
                        m.erase(nums[i]);
                    }
                    i++;
                }
            }
            count = count + j-i+1;
            j++;
        }

        return count;
    }

    int subarraysWithKDistinct(vector<int>& nums, int x) {

        return atmost(nums,x)-atmost(nums,x-1);

    }
};