class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<int> factorCounts(n + 1, 0);
        long long minPrice = LLONG_MAX;

        for (const auto& item : items) {
            int factor = item[0];
            long long price = item[1];
            factorCounts[factor]++;
            minPrice = min(minPrice, price);
        }

        // multiples[f] = total number of items whose factor is divisible by f
        vector<int> multiples(n + 1, 0);
        for (int f = 1; f <= n; f++) {
            if (factorCounts[f] == 0) continue;
            for (int m = f; m <= n; m += f) {
                multiples[f] += factorCounts[m];
            }
        }

        // Pair each item's price with how many boosted (2-item) copies it offers
        vector<pair<long long, long long>> deals;
        deals.reserve(n);
        for (const auto& item : items) {
            long long price = item[1];
            long long gain = multiples[item[0]] - 1; // exclude the item itself
            if (gain > 0 && price <= 2 * minPrice) {
                deals.push_back({price, gain});
            }
        }

        // Buy the cheapest boosted copies first
        sort(deals.begin(), deals.end());

        long long totalItems = 0;
        long long remainingBudget = budget;

        for (const auto& [price, limit] : deals) {
            if (remainingBudget < price) break;
            long long copies = min(limit, remainingBudget / price);
            totalItems += copies * 2;
            remainingBudget -= copies * price;
        }

        // Spend all remaining budget on the cheapest single item
        totalItems += remainingBudget / minPrice;

        return (int)totalItems;
    }
};