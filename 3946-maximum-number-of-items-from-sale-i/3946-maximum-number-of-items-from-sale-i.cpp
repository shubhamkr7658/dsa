class Solution {

public:
int dp[1001][1501][2];
int solve(vector<vector<int>>& items, int budget, vector<int>& vec, int n, int i, int p) {

if (i >= n) {

return 0;

}

if (dp[i][budget][p] != -1) {

return dp[i][budget][p];

}



int take1 = 0;

int untake = 0;

if (items[i][1] <= budget) {

if (p == 0) {

take1 = 1 + vec[i] + solve(items, budget - items[i][1], vec, n, i, 1);

} else {

take1 = 1 + solve(items, budget - items[i][1], vec, n, i, 1);

}

}

untake = solve(items, budget, vec, n, i + 1, 0);

return dp[i][budget][p] = max(take1, untake);

}



int maximumSaleItems(vector<vector<int>>& items, int budget) {

int n = items.size();

vector<int> vec(n, 0);

for (int i = 0; i < n; i++) {

for (int j = 0; j < n; j++) {

if (i != j && items[j][0] % items[i][0] == 0) {

vec[i]++;

}

}

}

memset(dp,-1,sizeof(dp));

return solve(items, budget, vec, n, 0, 0);

}

};