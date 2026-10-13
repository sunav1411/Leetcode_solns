class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for(auto& num : nums) num *= num;
        auto b = nums.begin();
        auto m = b + nums.size() / 2;
        auto e = nums.end();
        nth_element(b, m, e);
        return accumulate(m, e, 0ll) - accumulate(b, m, 0ll);         
    }
};