class Solution {
public:
    int totalFruit(vector<int>& nums) {
        int j =0;
        unordered_map<int,int> m;
        int ans =0;

        for(int i =0;i<nums.size();i++){
            m[nums[i]]++;

            if(m.size() <= 2){
                ans = max(ans,i-j+1);
                //cout<<i<<" "<<j<<"\n";
            }
            else{
                while(j < i){
                    m[nums[j]]--;
                    if(m[nums[j]] == 0){
                        m.erase(nums[j]);
                        j++;
                        ans = max(ans,i-j+1);
                        //cout<<i<<" "<<j<<"\n";
                        break;        
                    }
                    j++;
                }
            }
        }

        return ans;
    }
};