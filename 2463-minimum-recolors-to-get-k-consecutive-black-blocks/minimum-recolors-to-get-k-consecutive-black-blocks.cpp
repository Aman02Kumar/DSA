class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        
        //sliding window
        int i = 0, j = 0;

        int minOperation = k;
        int White = 0;

        while(j < n){
            if(blocks[j] == 'W')White++;

            if(j - i + 1 == k){
                minOperation = min(minOperation, White);

                if(blocks[i] == 'W')White--;
                i++;
            }
            j++;
        }
        return minOperation;
    }
};