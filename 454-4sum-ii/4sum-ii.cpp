class Solution {
public:
   int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
       unordered_map<int, int> mp;

       
       for (int k : nums1) {
           for (int l : nums2) {
               mp[k + l]++;
           }
       }

       int count = 0;

       
       for (int i : nums3) {
           for (int j : nums4) {
               count += mp[-(i + j)];
           }
       }

       return count;
   }
};