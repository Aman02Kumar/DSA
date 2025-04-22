class Solution {
public:
    int minimizedStringLength(string s) 
    {
        int i=0;
        int count=1;
        sort(s.begin(),s.end());
        for(int j=1;j<s.length();j++)    
        {
            if(s[j]!=s[i])
            {
                i++;
                count++;
                s[i]=s[j];
            }
        }
        return count;
    }
};