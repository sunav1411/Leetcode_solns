class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n=nums.size();
        vector<int> divs,sorted=nums;
        sort(sorted.begin(),sorted.end());

        for(int i=1;i*i<=n;i++){
            if(n%i==0) {
                divs.push_back(i);  
                if(i!=n/i)  divs.push_back(n/i);  
            }
        }

        int ans=0;

        for(int k:divs){
            bool ok=true;
            int prevmax=0;

            for(int s=0;s<n;s+=k){
                int e=s+k-1;
                int mn=nums[s];
                int mx=nums[s];
                int drops=0;

                for(int j=s;j<=e;j++){
                    mn=min(nums[j],mn);
                    mx=max(nums[j],mx);

                    if(j<e && nums[j]>nums[j+1])
                        drops++;
                }
                    
                if(nums[e]>nums[s]) 
                    drops++;
                
                if(drops>1){
                    ok=false;
                    break;
                }

                if(s>0 && prevmax>mn){
                    ok=false;
                    break;
                }
                prevmax=mx;
            }
            if(ok)
                ans+=k;
        }
        return ans;
    }
};