class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans = 0 ;
        int first = 0;
        int second = 0;
        for(int i = 0 ; i < bank.size();i++){

            if(first == 0){
            for(auto ch : bank[i]){
                if(ch =='1'){
                    first++;
                }
            }
            }

            else {
                for(auto ch : bank[i]){
                    if(ch =='1'){
                        second++;
                    }
                }
            }

            if(first && second) {
                ans+= first* second;
                first  = second ;
                second = 0;
                }



        }
        return ans;
    }
};