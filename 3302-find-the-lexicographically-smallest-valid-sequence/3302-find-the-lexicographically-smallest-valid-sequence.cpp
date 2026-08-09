class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        // last[j] = index in word1 where word2[j] can be matched
        // while matching word2 from right to left.
        vector<int> last(m, -1);

        int i = n - 1;
        int j = m - 1;

        while (i >= 0 && j >= 0) {
            if (word1[i] == word2[j]) {
                last[j] = i;
                j--;
            }
            i--;
        }

        vector<int> ans(m);

        bool canMismatch = true;
        j = 0;

        for (i = 0; i < n && j < m; i++) {

            // Exact match
            if (word1[i] == word2[j]) {
                ans[j] = i;
                j++;
            }

            // Use the one allowed mismatch
            else if (canMismatch &&
                     (j == m - 1 || i < last[j + 1])) {

                ans[j] = i;
                j++;
                canMismatch = false;
            }
        }

        if (j == m)
            return ans;

        return {};
    }
};