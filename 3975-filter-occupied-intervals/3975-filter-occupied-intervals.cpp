
class Solution{
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals,int freeStart,int freeEnd){
        sort(occupiedIntervals.begin(),occupiedIntervals.end());

        vector<vector<int>> a,b;

        for(auto &x:occupiedIntervals){
            if(a.empty()){
                a.push_back(x);
                continue;
            }

            if(x[0]<=a.back()[1]+1)
                a.back()[1]=max(a.back()[1],x[1]);
            else
                a.push_back(x);
        }

        for(auto &x:a){
            int l=x[0];
            int r=x[1];

            if(r<freeStart||l>freeEnd){
                b.push_back({l,r});
                continue;
            }

            if(l<freeStart)
                b.push_back({l,freeStart-1});

            if(r>freeEnd)
                b.push_back({freeEnd+1,r});
        }

        return b;
    }
};