class Solution {
public:
    int root[26];
    void unio(){
        for(int i=0;i<26;i++){
            root[i] = i;
        }
    }
    int parent (int x){
        return (x == root[x]) ? x : root[x] = parent(root[x]);
    }
    void add(int x, int y){
        int px = parent(x);
        int py = parent(y);
        if(px == py)return;
        else if(px<py)root[py] = px;
        else root[px] = py;
    }
    string smallestEquivalentString(string s1, string s2, string b) {
        unio();
        for(int i=0;i<s1.size();i++){
            add(s1[i]-'a', s2[i]-'a');
        }
        string ans = "";
        for(int i=0;i<b.size();i++){
            ans += 'a' + parent(b[i]-'a');
        }
        return ans;
    }
};