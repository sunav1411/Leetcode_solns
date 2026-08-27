class Solution{
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,vector<int>& newInterval){
        vector<vector<int>> result;
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end());

        result.push_back(intervals[0]);
        for(int idx=1;idx<intervals.size();idx++){
            if(result.back()[1]>=intervals[idx][0])
                result.back()[1]=max(result.back()[1],intervals[idx][1]);
            else
                result.push_back(intervals[idx]);
        }
        return result;
    }
};