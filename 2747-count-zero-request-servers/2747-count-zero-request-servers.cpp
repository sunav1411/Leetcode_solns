class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs,
                             int x, vector<int>& queries) {

        // Sort logs by timestamp
        sort(logs.begin(), logs.end(),
             [](vector<int>& a, vector<int>& b) {
                 return a[1] < b[1];
             });

        // Store query time along with original index
        vector<pair<int, int>> q;

        for(int i = 0; i < queries.size(); i++) {
            q.push_back({queries[i], i});
        }

        sort(q.begin(), q.end());

        // Frequency of logs for each server
        vector<int> hash(n + 1, 0);

        int l = 0, r = 0;
        int active = 0;
        int m = logs.size();

        vector<int> ans(queries.size());

        for(auto [t, i] : q) {

            // Include logs within the upper boundary
            while(r < m && logs[r][1] <= t) {
                int id = logs[r][0];

                if(hash[id] == 0)
                    active++;

                hash[id]++;
                r++;
            }

            // Remove logs outside the lower boundary
            while(l < m && logs[l][1] < t - x) {
                int id = logs[l][0];

                hash[id]--;

                if(hash[id] == 0)
                    active--;

                l++;
            }

            // Store answer at original query index
            ans[i] = n - active;
        }

        return ans;
    }
};