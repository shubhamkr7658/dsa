class Solution {
public:
vector<int>dp;
int solve(int n){
    if(n==0){
        return 0;
    }
    if(n<0){
        return 1e5;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    int k=1;
    int ans=1e5;
    for(k;k*(k+1)/2<=n;k++){
        int p=k*(k+1)/2;
        if(n-p==0){
            ans=min(ans,k);
            break;
        }
   ans=min(ans,k+1+solve(n-p));
    }
    return dp[n]=ans;
}
    int minDays(int n) {
        dp.assign(n+1,-1);
     return solve(n);   
    }
};