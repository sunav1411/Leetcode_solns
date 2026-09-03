class Solution {
public:
    int longestSubstring(string s, int k) {
         if(s.size()<k) return 0;

    vector<int> ginti(26,0);
    for(char c:s)
        ginti[c-'a']++;

    for(int i=0;i<s.size();i++){
        if(ginti[s[i]-'a']<k){
            int baaya=longestSubstring(s.substr(0,i),k);
            int daaya=longestSubstring(s.substr(i+1),k);
            return max(baaya,daaya);
        }
    }
    return s.size();
    }
};