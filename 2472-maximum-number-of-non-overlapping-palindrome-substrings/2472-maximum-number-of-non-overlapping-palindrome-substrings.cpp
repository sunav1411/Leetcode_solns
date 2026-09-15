class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.length();
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        for(int i = n-1; i>=0; i--){
            for(int j = i; j<n; j++){
                if(i==j)dp[i][j] = true;
                else if(j==i+1)dp[i][j] = s[i]==s[j];
                else dp[i][j] = s[i]==s[j] && dp[i+1][j-1];
            }
        }
        int count = 0;
        int prevIdx = -1;
        for(int j = 0; j<n; j++){
            for(int i = prevIdx+1; i<=j-k+1; i++){
                if(dp[i][j]){
                    count++;
                    prevIdx = j;
                    break;
                }
            }
        }
        return count;
    }
};