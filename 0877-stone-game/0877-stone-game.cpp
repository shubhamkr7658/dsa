class Solution {
public:
int dp[501][501];
int solve(vector<int>&piles,int c,int i,int j){

 if(i>j){
    return 0;
 }
 if(dp[i][j]!=-1){
    return dp[i][j];
}
 int left,right;
 if(c==1){
    left=piles[i]+solve(piles,0,i+1,j);
    right=piles[j]+solve(piles,0,i,j-1);
    return dp[i][j]=min(left,right);
 }
 left=piles[i]+solve(piles,1,i+1,j);
 right=piles[j]+solve(piles,1,i,j-1);
 return dp[i][j]=(max(left,right));
}
    bool stoneGame(vector<int>& piles) {
        memset(dp,-1,sizeof(dp));
        int sum=0;
    int ans=solve(piles,0,0,piles.size()-1);
    for(auto &t:piles){
   sum+=t;
    }
    if(sum-ans<ans){
      return true;
    }
    return false;
    }
};