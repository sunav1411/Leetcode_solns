class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n+1,0);
        dp[0]=0;
        for(int i=1;i<n+1;i++){
            int a=INT_MAX,b=INT_MAX,c=INT_MAX;
            a=dp[i-1]+1;
            if(i-2 >=0){
                b=dp[i-2]+4;
            }
            if(i-3>=0){
                c=dp[i-3]+9;
            }
            int mini=min({a,b,c});
            dp[i]=costs[i-1]+mini;
        }
        return dp[n];
    }
};