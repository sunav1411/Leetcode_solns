class Solution{
public:
    bool checkInclusion(string s1,string s2){
        if(s2.size()<s1.size()) return false;

        map<char,int> mp;
        for(char ch:s1) mp[ch]++;

        int match=0,total=s1.size();
        int left=0,right=0;

        auto hasChar=[&](char ch){
            return mp.find(ch)!=mp.end();
        };

        while(right<s2.size()){
            if(hasChar(s2[right])){
                if(mp[s2[right]]>0) match++;
                mp[s2[right]]--;
            }
            right++;

            while(right-left>total){
                if(hasChar(s2[left])){
                    if(mp[s2[left]]>=0) match--;
                    mp[s2[left]]++;
                }
                left++;
            }

            if(match==total) return true;
        }
        return false;
    }
};