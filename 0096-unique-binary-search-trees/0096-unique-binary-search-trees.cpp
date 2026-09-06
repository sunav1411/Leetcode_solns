class Solution {
public:
vector<vector<int>> dp;

int ginti(int low,int high){
    if(low>high) return 1;

    if(dp[low][high]!=-1)
        return dp[low][high];

    int ans=0;

    for(int root=low;root<=high;root++){
        int left=ginti(low,root-1);
        int right=ginti(root+1,high);
        ans+=left*right;
    }

    return dp[low][high]=ans;
}

int numTrees(int n){
    dp.resize(n+1,vector<int>(n+1,-1));
    return ginti(1,n);
}
};