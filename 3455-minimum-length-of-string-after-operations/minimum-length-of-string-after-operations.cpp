class Solution {
public:
    int minimumLength(string s) {

      int n=s.length();
 
    vector<int> mp(26,0);
      int count=0;
         
         for(auto x:s){
            
            mp[x-'a']++;
            if(mp[x-'a']==3){
                count++;
             
              mp[x-'a']=1;
            }
         }



      return n-2*count ;
    }
};