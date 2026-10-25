class Solution {
public:
int dp[201][201];
int solve(vector<vector<int>>& triangle,int &n,int i,int j){
    if(j>=triangle[i].size()){
        return INT_MAX;
    }
    if(i==n-1){
        return triangle[i][j];
    }

    if(dp[i][j]!=INT_MAX){
        return dp[i][j];
    }
    int take1=solve(triangle,n,i+1,j);
    int take2=solve(triangle,n,i+1,j+1);
    return dp[i][j]=triangle[i][j]+min(take1,take2);
}
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
       fill(&dp[0][0], &dp[0][0] + 201 * 201, INT_MAX);
        return solve(triangle,n,0,0);
    }
};