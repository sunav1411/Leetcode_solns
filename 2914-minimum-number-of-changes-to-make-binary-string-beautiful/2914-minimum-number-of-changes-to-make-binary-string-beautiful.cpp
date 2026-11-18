class Solution {
public:
    int minChanges(string str) {
        int n = str.size();
        int ans = 0;
        for(int i = 0; i < n; i += 2) {
            if(str[i] != str[i+1]) {
                ans++;
            }
        }
        return ans;
    }
};