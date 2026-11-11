class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long total_cost = 0;

        if (1LL * cost1 + cost2 <= costBoth) {
            int min_need = min(need1, need2);
            total_cost += 1LL * min_need * (cost1 + cost2);

            if (min_need < need1) {
                total_cost += 1LL * (need1 - min_need) * cost1;
            }
            if (min_need < need2) {
                total_cost += 1LL * (need2 - min_need) * cost2;
            }
        } else {
            int min_need = min(need1, need2);

            total_cost += 1LL * min_need * costBoth;

            if (need1 > min_need) {
                int remaining = need1 - min_need;
                if (cost1 < costBoth) {
                    total_cost += 1LL * remaining * cost1;
                } else {
                    total_cost += 1LL * remaining * costBoth;
                }
            }

            if (need2 > min_need) {
                int remaining = need2 - min_need;
                if (cost2 < costBoth) {
                    total_cost += 1LL * remaining * cost2;
                } else {
                    total_cost += 1LL * remaining * costBoth;
                }
            }
        }
        return total_cost;
    }
};