class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        int n = nums.size();
        int ans = 0;
        int median = 0;
        if (n % 2 == 0) {
            median = (nums[n / 2 - 1] + nums[n / 2]) / 2;
        }
        else {
            median = nums[n / 2];
        }
        for (int i = 0; i < n; i++) {
            if (median - nums[i] > 0) {
                ans = ans + (median - nums[i]);
            } else {
                ans = ans + (nums[i] - median);
            }
        }
        return ans;
    }
}
;