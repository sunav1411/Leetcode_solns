class Solution{
public:
    vector<int> circularPermutation(int n,int start){
        int curr=start;
        map<int,int> seen;
        vector<int> ans;
        seen[curr]++;
        ans.push_back(curr);

        while(seen.size()<(1<<n)){
            for(int bit=0;bit<n;bit++){
                int next=curr^(1<<bit);
                if(seen.find(next)==seen.end()){
                    ans.push_back(next);
                    seen[next]++;
                    curr=next;
                    break;
                }
            }
        }
        return ans;
    }
};