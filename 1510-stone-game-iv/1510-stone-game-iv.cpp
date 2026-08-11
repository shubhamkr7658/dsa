class Solution {
public:
    vector<int> dp;

    bool solve(int n) {
        // No stones -> current player loses
        if (n == 0)
            return false;

        // Already calculated
        if (dp[n] != -1)
            return dp[n];

        int t = sqrt(n);

        // Try every possible square
        for (int i = 1; i <= t; i++) {
            // If this move makes opponent lose,
            // current player wins
            if (solve(n - i * i) == false) {
                return dp[n] = true;
            }
        }

        // No winning move exists
        return dp[n] = false;
    }

    bool winnerSquareGame(int n) {
        dp.resize(n + 1, -1);
        return solve(n);
    }
};