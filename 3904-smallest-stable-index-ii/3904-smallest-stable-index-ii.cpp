class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        int maxx=INT_MIN;
        vector<int> minn(n);
        minn[n-1]=nums[n-1];

        for(int i=n-2;i>=0;i--){
            minn[i]=min(minn[i+1],nums[i]);
        }

        for(int i=0;i<n;i++){
            maxx=max(maxx,nums[i]);
            if((maxx-minn[i])<=k) return i;
        }
        return -1;
    }   
};