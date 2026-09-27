class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        auto minaveloru=nums;

        int jiju=0;
        int n=nums.size();

        for(int i=0;i<n;i++){
            long long jodo=0;
            vector<bool>seen(k, false);
            for(int j=i;j<n;j++){
                jodo=jodo+nums[j];

                if(jodo%k==0){
                    jiju=max(jiju,j-i+1);
                }

                int sumRem=((jodo % k) + k) % k;

                int xRem=((nums[j] % k) + k) % k;
                int twice=(2LL * xRem) % k;

                seen[twice]=true;

                if(seen[sumRem]){
                    jiju = max(jiju, j-i+1);
                }
            }
        }
        return jiju;
    }
    
};