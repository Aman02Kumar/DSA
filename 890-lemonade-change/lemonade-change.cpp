class Solution {
public:
    bool lemonadeChange(vector<int>& arr) {
        int f = 0 , t = 0;
        for(int i = 0 ;  i < arr.size();i++){
            if(arr[i]==5){
                f++;
            }
            else if(arr[i]==10){
                if(f>0){
                    t++;
                    f--;
                }
                else return false;
                
            }
            else if(arr[i]==20){
                
                if(f >0 && t>0){
                    f--;
                    t--;
                }
               else  if(f>=3){
                    f=f-3;
                }
                else return false;
            }       
        }
        return true;
    }
};