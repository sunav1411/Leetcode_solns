class Solution{
public:
    int findMinDifference(vector<string>& timePoints){
        vector<int> mins(timePoints.size());
        for(int idx=0;idx<mins.size();idx++)
            mins[idx]=timePoints[idx][0]*600+timePoints[idx][1]*60+timePoints[idx][3]*10+timePoints[idx][4];

        int ans=INT_MAX;
        sort(mins.begin(),mins.end());

        for(int idx=0;idx<mins.size()-1;idx++){
            int diff=mins[idx+1]-mins[idx];
            ans=min(ans,diff);
        }

        ans=min(ans,1440-(mins.back()-mins[0]));
        return ans;
    }
};