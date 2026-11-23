class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        if (n < 3) return -1;

        int maxi = *max_element(nums.begin(), nums.end());
        int V = maxi + n;

        const long long INF = 1e18;

        vector<vector<long long>> left(n, vector<long long>(V + 1, INF));
        vector<vector<long long>> right(n, vector<long long>(V + 1, INF));

        // Increasing part
        for (int v = 1; v <= V; v++) {
            left[0][v] = abs(nums[0] - v);
        }

        for (int i = 1; i < n; i++) {
            long long best = INF;

            for (int v = 1; v <= V; v++) {
                left[i][v] = best + abs(nums[i] - v);
                best = min(best, left[i - 1][v]);
            }

            // Correct strict inequality: previous value < current value
            best = INF;
            for (int v = 1; v <= V; v++) {
                left[i][v] = best + abs(nums[i] - v);
                best = min(best, left[i - 1][v]);
            }
        }

        // Decreasing part
        for (int v = 1; v <= V; v++) {
            right[n - 1][v] = abs(nums[n - 1] - v);
        }

        for (int i = n - 2; i >= 0; i--) {
            long long best = INF;

            for (int v = 1; v <= V; v++) {
                right[i][v] = best + abs(nums[i] - v);
                best = min(best, right[i + 1][v]);
            }
        }

        long long ans = INF;

        // Try every possible peak and peak value
        for (int i = 1; i < n - 1; i++) {
            for (int v = 1; v <= V; v++) {
                ans = min(ans,
                    left[i][v] + right[i][v] - abs(nums[i] - v));
            }
        }

        return ans == INF ? -1 : (int)ans;
    }
};
