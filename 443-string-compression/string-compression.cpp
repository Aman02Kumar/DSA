class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();

        int index = 0 ; 
        int i = 0 ;

        while(i<n){

            int cnt = 0;
            char cc = chars[i];

            // finding count of duplicatess
            while(i < n && chars[i] == cc){
                cnt++;
                i++;
            }

            // now do the asssign work
            chars[index] = cc;
            index++;

            if(cnt > 1 ){

                string str = to_string(cnt);
                for(auto it : str){
                    chars[index] = it;
                    index++;
                }
            }

        }
        return index;
    }
};