class Solution {
public:
bool wordPattern(string pattern,string s){
    vector<string> shabd;
    string word;
    stringstream ss(s);

    while(ss>>word)
        shabd.push_back(word);

    if(pattern.size()!=shabd.size())
        return false;

    unordered_map<char,string> map1;
    unordered_map<string,char> map2;

    for(int i=0;i<pattern.size();i++){
        char ch=pattern[i];
        string curr=shabd[i];

        if(map1.count(ch)&&map1[ch]!=curr)
            return false;

        if(map2.count(curr)&&map2[curr]!=ch)
            return false;

        map1[ch]=curr;
        map2[curr]=ch;
    }
    return true;
}
};