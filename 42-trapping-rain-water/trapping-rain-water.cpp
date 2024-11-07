class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size();
        vector<int> lft(n), rit(n);

        for(int i=0;i<height.size();i++)
        {
            if(i==0) lft[i] = height[i];
            else lft[i] = max(lft[i-1], height[i]);
        }
        for(int i=height.size() - 1;i>=0;i--)
        {
            if(i == height.size() -1) rit[i] = height[i];
            else rit[i] = max(rit[i+1], height[i]);
        }


        int trapWater = 0;
        for(int i=0;i<height.size();i++)
        {
            trapWater+= min(lft[i],rit[i]) - height[i];
        }
        return trapWater;
    }
};