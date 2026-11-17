
class Solution {
public:
    int dp[201][201];
    int memo[201][201];
    int size = 0;

    int find_cost(int start, int end, string &s) {
        if(dp[start][end] != -1)
            return dp[start][end];

        int len = end - start + 1;
        int cost = 4000;

        if(len==1)  return 4000; 

        for(int d = 1; d < len; d++) {
            if(len % d == 0) {
                int temp = 0;
                int m = len / d;

                for(int j = 0; j < d; j++) {
                    for(int t = 0; t < m / 2; t++) {

                        int l = start + j + t * d;
                        int r = start + j + (m - 1 - t) * d;

                        if(s[l] != s[r])
                            temp++;
                    }
                }

                cost = min(cost, temp);
            }
        }

        return dp[start][end] = cost;
    }

    int split_k(int index, int k, string &s) {
        if(k == 0)
            return index == size ? 0 : 400;

        if(index + 2*k - 1 >= size) return 400;

        if(size - index < k)
            return 400;
        
        if(memo[index][k] != -1)
            return memo[index][k];

        int cost = 400;

        for(int end = index; end <= size-k; end++) {
            cost = min(cost,
                find_cost(index, end, s) +
                split_k(end + 1, k - 1, s));
        }

        return memo[index][k] = cost;
    }

    int minimumChanges(string s, int k) {
        size = s.length();

        memset(dp, -1, sizeof(dp));
        memset(memo, -1, sizeof(memo));

        return split_k(0, k, s);
    }
};