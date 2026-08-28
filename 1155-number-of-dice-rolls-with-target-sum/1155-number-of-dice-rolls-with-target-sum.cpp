class Solution{
public:
    int mod=1e9+7;
    vector<vector<int>> dp;

    int recur(int dice,int rem,int n,int k){
        if(dice==n) return rem==0;
        if(rem<0) return 0;
        if(dp[dice][rem]!=-1) return dp[dice][rem];

        int ways=0;
        for(int face=1;face<=k;face++)
            ways=(ways+recur(dice+1,rem-face,n,k))%mod;

        return dp[dice][rem]=ways;
    }

    int numRollsToTarget(int n,int k,int target){
        dp.resize(n+1,vector<int>(target+1,-1));
        return recur(0,target,n,k);
    }
};