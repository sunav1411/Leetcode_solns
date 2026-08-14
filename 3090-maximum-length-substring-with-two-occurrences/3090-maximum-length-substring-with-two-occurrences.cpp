class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char, int> mp;
        int n=s.size();
        int left=0, right=0;
        int result=0;
        while(right<n){
            mp[s[right]]++;
            if(mp[s[right]]<=2){
                result=max(result, (right-left+1));
                
            }
            else {
                while(mp[s[right]]>2){
                    mp[s[left]]--;
                    left++;
                }
            }
            right++;  
        }
        return result;
    }
};


