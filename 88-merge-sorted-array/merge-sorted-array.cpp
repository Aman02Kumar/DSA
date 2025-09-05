class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int l = nums1.size()-1;
        int r = 0 ;
        while(l >= 0 && r< nums2.size()){
            if(nums1[l] >= nums2[r]){
                swap(nums1[l],nums2[r]);
                l--;
                r++;

            }
            else continue;
        }

        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());

    }
};