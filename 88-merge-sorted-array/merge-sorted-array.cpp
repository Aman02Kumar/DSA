class Solution {
public:
    void merge(vector<int>& a, int n, vector<int>& b, int m) {
        
        int i=0,j=0;
        while(i<n && j < m){

            if(a[i] <= b[j]){
                i++;
            }
            else if(a[i] > b[j]){
                int x = a[i];
                a[i] = b[j];
                b[j] = x;
                sort(b.begin(),b.end());
                i++;
            }
            
        }
          while (j < m) {
            a[i] = b[j];
            i++;
            j++;
        }


    }
};