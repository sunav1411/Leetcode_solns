class Solution {
public:
int flipLights(int n,int presses){
    n=min(n,6);
    string shuru(n,'1');
    unordered_set<string> mila,dekha;
    dfs(shuru,presses,mila,dekha);
    return mila.size();
}

private:
void dfs(string haal,int presses,unordered_set<string>& mila,
         unordered_set<string>& dekha){
    string key=haal+"_"+to_string(presses);
    if(dekha.count(key)) return;
    dekha.insert(key);

    if(presses==0){
        mila.insert(haal);
        return;
    }

    dfs(sabBadlo(haal),presses-1,mila,dekha);
    dfs(evenBadlo(haal),presses-1,mila,dekha);
    dfs(oddBadlo(haal),presses-1,mila,dekha);
    dfs(teenBadlo(haal),presses-1,mila,dekha);
}

string sabBadlo(string s){
    for(char &c:s)
        c=(c=='1')?'0':'1';
    return s;
}

string evenBadlo(string s){
    for(int i=1;i<s.size();i+=2)
        s[i]=(s[i]=='1')?'0':'1';
    return s;
}

string oddBadlo(string s){
    for(int i=0;i<s.size();i+=2)
        s[i]=(s[i]=='1')?'0':'1';
    return s;
}

string teenBadlo(string s){
    for(int i=0;i<s.size();i++)
        if(i%3==0)
            s[i]=(s[i]=='1')?'0':'1';
    return s;
}
};