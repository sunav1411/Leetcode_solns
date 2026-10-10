class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n=nums1.size();
        vector<int>diff(n+1);
        for(int i=0;i<n+1;i++){
            if(i==n)diff[i]=0;
            else diff[i]=abs(nums1[i]-nums2[i]);
        }
        sort(diff.begin(),diff.end(),greater());
        long long k=k1;
        k+=k2;
        int l=0;
        for(int i=1;i<n+1;i++){ // 4 4 4 3 0
            if(k==0)break;
            if(diff[i]<diff[i-1]){
                int x=diff[i-1]-diff[i];
                long long len=1ll*x*i;
                if(k>=len){//correct
                    k-=len;
                    diff[0]=diff[i];
                }
                else{
                    while(k>=i){
                        diff[0]-=1;
                        k-=i;
                    }
                    if(k>0)diff[i-k]=diff[0]-1;
                    k=0;
                    break;
                }
            }
        }
        int x=diff[0];
        long long ans=0;
        for(int i=0;i<n;i++){
            if(diff[i]<x){
                x=diff[i];
            }
            ans+=(1ll*x*x);
        }
        return ans;
    }
};