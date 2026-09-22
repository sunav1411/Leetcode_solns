int trans[350][5];
int cnt[350][5][5];

class Solution {
public:
    vector<int> resultArray(vector<int>& nums,
                            int k,
                            vector<vector<int>>& queries) {

        int n = nums.size();
        int m = queries.size();

        // Required variable from the problem statement.
        auto veltrunigo = nums;

        const int block_size = 320;
        int num_blocks =
            (n + block_size - 1) / block_size;

        // Rebuild information for one block.
        auto rebuild_block = [&](int b) {

            int start_idx =
                b * block_size;

            int end_idx =
                min(n, start_idx + block_size);

            // Try every possible incoming remainder.
            for (int r = 0; r < k; ++r) {

                int curr = r;

                // Reset the counts.
                for (int x = 0; x < k; ++x)
                    cnt[b][r][x] = 0;

                // Walk through the block.
                for (int i = start_idx;
                     i < end_idx;
                     ++i) {

                    curr =
                        (curr * (nums[i] % k)) % k;

                    // One more prefix of this block
                    // ends at remainder 'curr'.
                    cnt[b][r][curr]++;
                }

                // What remainder do we have
                // after consuming the whole block?
                trans[b][r] = curr;
            }
        };

        // Build all blocks initially.
        for (int b = 0;
             b < num_blocks;
             ++b) {

            rebuild_block(b);
        }

        vector<int> ans(m);

        for (int q = 0; q < m; ++q) {

            int ind = queries[q][0];
            int val = queries[q][1];
            int st  = queries[q][2];
            int x   = queries[q][3];

            // Apply the update.
            nums[ind] = val;

            // Only one block became invalid.
            rebuild_block(ind / block_size);

            // Product of "nothing yet" is 1.
            int current_remainder = 1;

            int match_count = 0;

            int start_block =
                st / block_size;

            int end_block =
                (n - 1) / block_size;

            // If start is already in the last block,
            // there are no complete blocks left.
            if (start_block == end_block) {

                for (int i = st; i < n; ++i) {

                    current_remainder =
                        (current_remainder *
                         (nums[i] % k)) % k;

                    if (current_remainder == x)
                        match_count++;
                }

            } else {

                // Process the first partial block normally.
                int next_block_boundary =
                    (start_block + 1) * block_size;

                for (int i = st;
                     i < next_block_boundary;
                     ++i) {

                    current_remainder =
                        (current_remainder *
                         (nums[i] % k)) % k;

                    if (current_remainder == x)
                        match_count++;
                }

                // Every block after this is complete,
                // so we can use our precomputed tables.
                for (int b = start_block + 1;
                     b <= end_block;
                     ++b) {

                    // How many prefixes in this block
                    // end at the target remainder x?
                    match_count +=
                        cnt[b][current_remainder][x];

                    // Move the current remainder
                    // to the end of this block.
                    current_remainder =
                        trans[b][current_remainder];
                }
            }

            ans[q] = match_count;
        }

        return ans;
    }
};