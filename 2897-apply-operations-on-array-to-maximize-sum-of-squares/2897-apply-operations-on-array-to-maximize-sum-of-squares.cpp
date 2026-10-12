class Solution {
public:
    const int MOD = 1e9 + 7;

    void calculateBit(vector<int>& bit, int n) {
        for (int i = 0; i < 32; i++) {
            int b = 1 << i;
            if (n & b) bit[i]++;
        }
    }

    int maxSum(vector<int>& nums, int k) {
        vector<int> bit(32, 0);

        for (int i = 0; i < nums.size(); i++) {
            calculateBit(bit, nums[i]);
        }

        long long result = 0;

        for (int i = 0; i < k; i++) {
            long long number = 0;
            long long base = 1;
            long long x;

            for (int j = 0; j < 31; j++) {
                if (bit[j] > 0) {
                    bit[j]--;
                    x = 1;
                } else {
                    x = 0;
                }

                number = number + base * x;
                base *= 2;
            }

            number = ((number % MOD) * (number % MOD)) % MOD;
            result = (result % MOD + number % MOD) % MOD;
        }

        return result;
    }
};