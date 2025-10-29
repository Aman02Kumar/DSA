class Solution {
public:
    bool ispower(int x){
        return x>0 && !(x & (x-1));
    }
    int smallestNumber(int n) {

        int x = n+1;
        while(x){
            if(ispower(x)){
                return x-1;
            }
            x++;
        }
        
        return -1;
    }
};