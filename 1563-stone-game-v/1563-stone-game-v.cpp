class Solution {
public:
    vector<int> prefix;
    vector<vector<int>> dp;

    int getSum(int l, int r) {
        return prefix[r + 1] - prefix[l];
    }

    int ans(int i, int j) {

        if (i == j)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int lar = 0;

        for (int c = i; c < j; c++) {

            int leftSum = getSum(i, c);
            int rightSum = getSum(c + 1, j);

            int curr;

            if (leftSum == rightSum) {

                curr = leftSum +
                       max(ans(i, c), ans(c + 1, j));
            }

            else if (leftSum > rightSum) {

                curr = rightSum +
                       ans(c + 1, j);
            }

            else {

                curr = leftSum +
                       ans(i, c);
            }

            lar = max(lar, curr);
        }

        return dp[i][j] = lar;
    }

    int stoneGameV(vector<int>& stoneValue) {

        int n = stoneValue.size();

        // Standard prefix sum
        prefix.assign(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + stoneValue[i];
        }

        // dp[i][j] = maximum score Alice can get from [i...j]
        dp.assign(n, vector<int>(n, -1));

        return ans(0, n - 1);
    }
};