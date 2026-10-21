class Solution {
public:
    int minOperations(string s) {
        string sorted = s;
        int n = s.size(), count = 0, ans = 5;
        sort(sorted.begin(), sorted.end());

        if (sorted == s) return 0;
        if (n == 2) return -1;

        string left = s.substr(0, n-1), right;
        sort(left.begin(), left.end());
        left += s[n-1];

        if (left != s) count++;
        if (left == sorted) ans = count;
        else {
            right = left.substr(1, n-1);
            sort(right.begin(), right.end());
            right = left[0] + right;

            if (right != left) count++;
            if (right != sorted) count++;
            ans = count;
        }

        count = 0;
        right = s.substr(1, n-1);
        sort(right.begin(), right.end());
        right = s[0] + right;

        if (right != s) count++;
        if (right == sorted) ans = min(ans, count);
        else {
            left = right.substr(0, n-1);
            sort(left.begin(), left.end());
            left += right[n-1];

            if (left != right) count++;
            if (left != sorted) count++;
            ans = min(ans, count);
        }

        return ans;
    }
};