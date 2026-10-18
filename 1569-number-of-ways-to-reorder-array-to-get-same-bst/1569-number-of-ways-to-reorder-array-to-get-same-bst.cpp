class Solution {
public:
    typedef long long ll;
    ll MOD = 1e9 + 7;
    vector<vector<ll>> pascalTriangle;

    int solve(vector<int>& nums) {
        int n = nums.size();

        // Base case: fewer than three elements
        if (n < 3) {
            return 1;
        }

        int root = nums[0];

        vector<int> leftArray;
        vector<int> rightArray;

        // Divide into left and right subtrees
        for (int i = 1; i < n; i++) {
            if (nums[i] < root) {
                leftArray.push_back(nums[i]);
            } else {
                rightArray.push_back(nums[i]);
            }
        }

        // Count valid arrangements for both subtrees
        ll x = solve(leftArray) % MOD;
        ll y = solve(rightArray) % MOD;

        // Count possible interleavings
        ll z = pascalTriangle[n - 1][leftArray.size()];

        // Combine all three counts
        return (((x * y) % MOD * z) % MOD);
    }

    int numOfWays(vector<int>& nums) {
        int n = nums.size();

        // Build Pascal's Triangle
        pascalTriangle.resize(n + 1);

        for (int i = 0; i <= n; i++) {
            pascalTriangle[i] = vector<ll>(i + 1, 1);

            for (int j = 1; j < i; j++) {
                pascalTriangle[i][j] =
                    (pascalTriangle[i - 1][j - 1] +
                     pascalTriangle[i - 1][j]) % MOD;
            }
        }

        // Exclude the original ordering
        return (solve(nums) - 1 + MOD) % MOD;
    }
};