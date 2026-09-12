class Solution {
public:

    struct node{
        long long score = -1;
        vector <int> ind;
    };

    node solve(vector<vector<int>>& intervals, int i, int k,  vector <vector <node> > &dp){
        if(k == 0 || i == intervals.size()) return node();

        if(dp[i][k].score != -1) return dp[i][k]; 

        node skip, take;
        skip = solve(intervals, i + 1, k, dp);
        int nextIndex = intervals.size(), left = i + 1, right = intervals.size() - 1;

        while(left <= right){
            int mid = left + (right - left) / 2;
            if(intervals[mid][0] > intervals[i][1]){
                nextIndex = mid;
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        
        take = solve(intervals, nextIndex, k - 1, dp);
        take.score += intervals[i][2];
        take.ind.push_back(intervals[i][3]);

        sort(take.ind.begin(), take.ind.end());

        node result;

        if(take.score > skip.score){
            result = take;
        }else if(skip.score > take.score){
            result = skip;
        }else{
            result = (take.ind < skip.ind) ? take : skip;
        }
        dp[i][k] = result;
        return dp[i][k];
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        for(int i = 0; i < intervals.size(); i++){
            intervals[i].push_back(i);
        }

        sort(intervals.begin(), intervals.end());
        vector <vector <node> > dp(n + 1, vector <node> (5) );
        return solve(intervals, 0, 4, dp).ind;

    }
};