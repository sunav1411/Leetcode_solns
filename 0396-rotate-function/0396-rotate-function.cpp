class Solution{
public:
    using ll=long long;

    int maxRotateFunction(vector<int>& arr){
        int n=arr.size();
        ll sum=0,curr=0;

        for(int idx=0;idx<n;idx++){
            sum+=arr[idx];
            curr+=idx*1ll*arr[idx];
        }

        ll ans=curr;
        for(int idx=1;idx<n;idx++){
            curr=curr-(n-1)*1ll*arr[n-idx]+(sum-arr[n-idx]);
            ans=max(ans,curr);
        }

        return (int)ans;
    }
};