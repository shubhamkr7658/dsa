class Solution {
public:
int solve(vector<vector<int>>&grid,int n,int m,int i,int j,vector<vector<int>>&dp){
    if(i<0||j<0 ||i>=n||j>=m){
        return INT_MAX/2;
    }
    if(i==n-1 && j==m-1){
        return grid[i][j];
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int right=solve(grid,n,m,i,j+1,dp);
 
    int bottom=solve(grid,n,m,i+1,j,dp);

    return dp[i][j]=grid[i][j]+min(right,bottom);
}
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(grid,n,m,0,0,dp);
    }
};