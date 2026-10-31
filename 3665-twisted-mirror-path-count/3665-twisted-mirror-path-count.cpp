class Solution {
public:
int dp[501][501][3];
int mo=1e9+7;
int solve(vector<vector<int>>&grid,int n,int m,int i,int j,int d){
    if(i<0 || i>=n|| j<0|| j>=m){
        return 0;
    }
    if(i==n-1 && j==m-1){
        return 1;
    }
    if(dp[i][j][d+1]!=-1){
        return dp[i][j][d+1];
    }
    int a=0;
    int b=0;
    if(grid[i][j]==1 && d==1){
        a=solve(grid,n,m,i+1,j,0)%mo;
    }
    else if(grid[i][j]==1&& d==0){
        a=solve(grid,n,m,i,j+1,1)%mo;
    }
    else{
       a=solve(grid,n,m,i+1,j,0)%mo;
       b=solve(grid,n,m,i,j+1,1)%mo;
    }
    return dp[i][j][d+1]=(a+b)%mo;
}
    int uniquePaths(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        memset(dp,-1,sizeof(dp));
        return solve(grid,n,m,0,0,-1);
    }
};