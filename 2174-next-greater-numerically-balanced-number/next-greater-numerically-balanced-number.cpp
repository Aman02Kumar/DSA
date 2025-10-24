class Solution {
public:
    int nextBeautifulNumber(int n) {
        
        n += 1;
        unordered_map<char,int> mp;

        while(n){
            bool flag = true;

            string x = to_string(n);
            for(auto i : x){
                mp[i]++;
            }

            for( auto i : mp){
                if((i.first - '0' ) != i.second ){
                    flag = false;
                    n++;
                    mp.clear();
                    break;
                }
            }
            if(flag){
                return stoi(x);
            }
        }
        return -1;
    }
};