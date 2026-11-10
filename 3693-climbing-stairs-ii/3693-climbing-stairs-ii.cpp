class Solution {
public:

int solve(vector<int>&costs,int n,int i,vector<int>&dp){
    if(i==n-1){
        return costs[i];
    }
    else if(i>n-1){
        return 1e4+1;
    }
    if(dp[i+1]!=-1){
        return dp[i+1];
    }
    int a=INT_MAX;
    int b=INT_MAX;
    int c=INT_MAX;
   if(i==-1){
     a=1+solve(costs,n,i+1,dp);
     b=4+solve(costs,n,i+2,dp);
     c=9+solve(costs,n,i+3,dp);
     return min(a,min(b,c));
   }
    a=1+solve(costs,n,i+1,dp);
    b=4+solve(costs,n,i+2,dp);
     c=9+solve(costs,n,i+3,dp);

     return dp[i+1]=costs[i]+min(a,min(b,c));
   
   
     
}
    int climbStairs(int n, vector<int>& costs) {
        vector<int>dp(n+1,-1);
        return solve(costs,n,-1,dp);
    }
};