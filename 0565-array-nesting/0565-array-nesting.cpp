class Solution{
private:
    int find(vector<int>& par,int node){
        if(par[node]==node) return node;
        return par[node]=find(par,par[node]);
    }

    void union_(vector<int>& par,vector<int>& sz,int x,int y){
        int rootX=find(par,x);
        int rootY=find(par,y);

        if(sz[rootX]>=sz[rootY]){
            sz[rootX]++;
            par[rootY]=rootX;
        }else{
            sz[rootY]++;
            par[rootX]=rootY;
        }
    }

public:
    int arrayNesting(vector<int>& nums){
        int ans=0,n=nums.size();
        vector<int> sz,par;
        unordered_map<int,int> mp;

        for(int idx=0;idx<n;idx++){
            sz.push_back(0);
            par.push_back(idx);
        }

        for(int idx=0;idx<n;idx++)
            union_(par,sz,idx,nums[idx]);

        for(int idx=0;idx<n;idx++){
            int root=find(par,par[idx]);
            mp[root]++;
            ans=max(ans,mp[root]);
        }

        return ans;
    }
};