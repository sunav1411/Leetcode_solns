class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        size_t n = servers.size(), m = tasks.size();
        std::vector<int> output(m, 0);
        std::priority_queue<std::tuple<int, int>, std::vector<std::tuple<int, int>>, std::greater<std::tuple<int, int>>> available, process;
        // available: <weight, index>
        // process: <endTime, index>
        for (size_t i = 0; i < n; ++i) {
            available.push(std::tuple<int, int>{servers[i], i});
        }
        long long currentTime = 0;
        for (size_t j = 0; j < m; ++j) {
            if (j > currentTime) currentTime = j;
            while (available.empty() || (!process.empty() && currentTime >= std::get<0>(process.top()))) {
                auto [endTime, index] = process.top();
                currentTime = std::max(currentTime, 1LL * endTime);
                available.push(std::tuple<int, int>{servers[index], index});
                process.pop();
            }
            auto [weight, index] = available.top();
            available.pop();
            output[j] = index;
            process.push(std::tuple<int, int>{currentTime + tasks[j], index});
        }
        return output;
    }
};