class Solution {
public:
    const int mod=1e9+7;

    int distinctSubseqII(string s) {
        int n=s.size();
        vector<int> dp(n+1), pos(26);

        for(int i=1;i<=n;i++)
        {
            int c=s[i-1]-'a';

            dp[i]=(2*dp[i-1]+1)%mod;

            if(pos[c]!=0)
                dp[i]=(dp[i]-(dp[pos[c]-1]+1)+mod)%mod;

            pos[c]=i;
        }

        return dp[n];
    }
};