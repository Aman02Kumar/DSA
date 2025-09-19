class Spreadsheet {
public:
vector<vector<int>> v;
    Spreadsheet(int rows) {
        vector<vector<int>> v1(26,vector<int>(rows+1,0));v=v1;
    }
    
    void setCell(string cell, int val) {
        char ch1=cell[0];string s =cell.substr(1,cell.length()-1);
        v[ch1-'A'][stoi(s)]=val;
    }
    
    void resetCell(string cell) {
        char ch1=cell[0];string s =cell.substr(1,cell.length()-1);
        v[ch1-'A'][stoi(s)]=0;
    }
    
    int getValue(string f) {
         char ch1='$',ch2='$';int p =1,a=0, b=0;string s,s2;
        if(f[p]>='A' && f[p]<='Z'){ch1=f[1];p++;}
        while(f[p]!='+'){s.push_back(f[p]);p++;}p++;
        if(f[p]>='A' && f[p]<='Z'){ch2=f[p];p++;}
        while(p<f.length()){s2.push_back(f[p]);p++;}
        if(ch1!='$'){a=v[ch1-'A'][stoi(s)];}else{a=stoi(s);}
        if(ch2!='$'){b=v[ch2-'A'][stoi(s2)];}else{b=stoi(s2);}
        return a+b;
    }
};