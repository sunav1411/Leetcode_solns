class Solution {
    static const int MOD = 1e9 + 7;

    struct Node {
        long long sum, sqSum, lazy;
        Node() : sum(0), sqSum(0), lazy(0) {}
    };

    vector<Node> tree;
    int n;

    void apply(int node, int l, int r, long long val) {
        long long len = r - l + 1;

        tree[node].sqSum = (
            tree[node].sqSum
            + 2 * val * tree[node].sum
            + len * val % MOD * val
        ) % MOD;

        tree[node].sum = (
            tree[node].sum + len * val
        ) % MOD;

        tree[node].lazy = (tree[node].lazy + val) % MOD;
    }

    void push(int node, int l, int r) {
        if (tree[node].lazy == 0 || l == r)
            return;

        int mid = (l + r) / 2;
        long long val = tree[node].lazy;

        apply(node * 2, l, mid, val);
        apply(node * 2 + 1, mid + 1, r, val);

        tree[node].lazy = 0;
    }

    void update(int node, int l, int r,
                int ql, int qr) {
        if (ql > r || qr < l)
            return;

        if (ql <= l && r <= qr) {
            apply(node, l, r, 1);
            return;
        }

        push(node, l, r);

        int mid = (l + r) / 2;

        update(node * 2, l, mid, ql, qr);
        update(node * 2 + 1, mid + 1, r, ql, qr);

        tree[node].sum = (
            tree[node * 2].sum +
            tree[node * 2 + 1].sum
        ) % MOD;

        tree[node].sqSum = (
            tree[node * 2].sqSum +
            tree[node * 2 + 1].sqSum
        ) % MOD;
    }

public:
    int sumCounts(vector<int>& nums) {
        n = nums.size();
        tree.assign(4 * n, Node());

        vector<int> last(100001, -1);
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            int prev = last[nums[i]];

            update(1, 0, n - 1, prev + 1, i);

            ans = (ans + tree[1].sqSum) % MOD;

            last[nums[i]] = i;
        }

        return ans;
    }
};