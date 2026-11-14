class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        vector<int> pr(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            pr[i + 1] = pr[i] + nums[i];
        }
        multiset<int> window;
        int min_sum = INT_MAX;
        for (int i = l; i <= n; ++i) {
            window.insert(pr[i - l]);
            if (i - r - 1 >= 0) {
                window.erase(window.find(pr[i - r - 1]));
            }
            auto it = window.lower_bound(pr[i]);
            if (it != window.begin()) {
                --it;
                min_sum = min(min_sum, pr[i] - *it);
            }
        }
        return min_sum == INT_MAX ? -1 : min_sum;
    }
};