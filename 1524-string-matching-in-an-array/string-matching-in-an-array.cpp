class Solution {
public:
    vector<string> stringMatching(vector<string>& wo) {
        int n=wo.size();
        vector<string> v;
        for(int i=0; i<n; i++){
            string s1=wo[i];
            for(int j=0; j<n; j++){
                if(j!=i && wo[j].size()>=s1.size()){
                    string s2=wo[j];
                    bool f=s2.find(s1) != string::npos;
                    if(f==true){
                        v.push_back(s1);
                        break;
                    }
                }
            }
        }
        return v;
    }
};