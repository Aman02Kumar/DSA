// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        
        long long l = 0 ; 
        long long h = n;
        long long ans = h;

        while(l<=h) {
        long long m = (l+h)/2;
        if(isBadVersion(m)){
            ans = m ;
            h = m -1;
        }
        else l = m +1;

        }
        return ans;
    }
};