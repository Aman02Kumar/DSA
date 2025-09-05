class Solution {
public:
    int trap(vector<int>& h) {
        
        int n =h.size();
        int left = 0 ; 
        int right = n-1;
        int r = 0;
        int leftmax = 0;
        int rightmax = 0 ;

        while(left<=right){
            if(h[left] <= h[right]){
                if(leftmax <= h[left]){
                    leftmax = h[left];
                }
                else {
                    r += leftmax - h[left];
                }
                left++;
            }
            else{
                 if(rightmax <= h[right]){
                        rightmax = h[right];
                }
                else    r += rightmax - h[right];
                right--;
            }
        }
        return r;
    }
};