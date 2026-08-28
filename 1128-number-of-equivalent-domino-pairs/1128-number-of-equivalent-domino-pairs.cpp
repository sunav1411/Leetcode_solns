class Solution{
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes){
        vector<int> freq(100,0);
        int ans=0;

        for(auto& dom:dominoes){
            int a=dom[0],b=dom[1];
            if(a>b) swap(a,b);

            int key=10*a+b;
            ans+=freq[key];
            freq[key]++;
        }
        return ans;
    }
};