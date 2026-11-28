class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        int maxFactor = n;

        vector<int> freq(maxFactor + 1, 0);

        int minPrice = INT_MAX;

        for (auto& item : items) {
            freq[item[0]]++;
            minPrice = min(minPrice, item[1]);
        }

        vector<int> freeCount(maxFactor + 1, 0);

        for (int f = 1; f <= maxFactor; f++) {
            for (int j = f; j <= maxFactor; j += f) {
                freeCount[f] += freq[j];
            }

            if (freeCount[f] > 0) {
                freeCount[f]--;
            }
        }

        vector<pair<int, int>> deals;

        for (auto& item : items) {
            int factor = item[0];
            int price = item[1];

            int count = freeCount[factor];

            if (count > 0 && price <= 2LL * minPrice) {
                deals.push_back({price, count});
            }
        }

        sort(deals.begin(), deals.end());

        long long ans = 0;
        long long remaining = budget;

        for (auto& deal : deals) {
            long long price = deal.first;
            long long count = deal.second;

            long long buy = min(count, remaining / price);

            ans += buy * 2;
            remaining -= buy * price;
        }

        ans += remaining / minPrice;

        return (int)ans;
    }
};