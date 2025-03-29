class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
         unordered_map<int,int>mp;
        int result=0;

        int n =nums.size();
        for(int i =0;i<n;i++){
            result+=mp[nums[i]];
            // basic concept of this approach is ki same element ko phle kitni baar dekha hai uski frequency result me add kar do and you will get your answer 
            mp[nums[i]]++;
        
        }
        return result ;
    }
};