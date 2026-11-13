class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        // Each block stores {adjusted value, number of elements}.
        deque<pair<int, int>> blocks;
        long long cost = 0;
        long long answer = 0;
        int right = nums.size() - 1;

        for(int left = right; left>=0; left--){
            int value = nums[left];
            int merged_blocks = 1;
            // Prepending value raises the opening blocks up to value.
            while(!blocks.empty() && blocks.front().first <= value){
                auto [block_value, block_count] = blocks.front();
                blocks.pop_front();
                cost += ((long long)value - block_value)*block_count;
                merged_blocks += block_count;
            }
            blocks.push_front({value, merged_blocks});
            // Remove elements from the right until the window fits.
            while(cost > k){
                auto& [block_value, block_count] = blocks.back();
                cost -= (block_value - nums[right]);
                right--, block_count--;
                if(block_count==0) blocks.pop_back();
            }
            answer += (right - left + 1);
        }
        return answer;
    }
};