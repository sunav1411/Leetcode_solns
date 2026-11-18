class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        map<int, int> mp;
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        set<int> free;
        int mx = 0;
        int n = arrival.size();
        for (int i = 0; i < k; i++)
            free.insert(i);

        for (int i = 0; i < n; i++) {
            int a = arrival[i];
            int b = load[i];
            while (pq.size() > 0 && pq.top().first <= a) {
                free.insert(pq.top().second);
                pq.pop();
            }
            if (free.size() > 0) {
                auto it = free.lower_bound(i % k);

                if (it == free.end()) {
                    it = free.begin();
                }

                int s = *it;
                free.erase(it);
                pq.push({a + b, s});
                mp[s]++;
                mx = max(mx, mp[s]);
            }
        }

        vector<int> ans;
        for (auto it : mp) {
            if (it.second == mx)
                ans.push_back(it.first);
        }
        return ans;
    }
};