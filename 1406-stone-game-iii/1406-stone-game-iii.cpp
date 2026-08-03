class Solution {
public:
int dp[50001][2];
int solve(vector<int>&value,int i,int p){
if(i>=value.size()){
    return 0;
}
if(dp[i][p]!=-1){
    return dp[i][p];
}
int first = INT_MIN;
int second = INT_MIN;
int third = INT_MIN;
if(p==1){
int mini;
   
    first=solve(value,i+1,0);
 
    second=solve(value,i+2,0);
   
    third=solve(value,i+3,0);
    mini=min(first,second);
    mini=min(mini,third);
    return dp[i][p]=mini;

}
   if(i<value.size())
    first=value[i]+solve(value,i+1,1);
    if(i+1<value.size())
    second=value[i]+value[i+1]+solve(value,i+2,1);
    if(i+2<value.size())
    third=value[i]+value[i+1]+value[i+2]+solve(value,i+3,1);
  int mini=max(first,second);
    mini=max(mini,third);
    return dp[i][p]=mini;

}
    string stoneGameIII(vector<int>& stoneValue) {
    memset(dp,-1,sizeof(dp));
     int ans=solve(stoneValue,0,0);
     int sum=0;
     for(auto &t:stoneValue){
   sum+=t;
     }
     if(sum-ans==ans){
        return "Tie";
     }
     if(sum-ans<ans){
        return "Alice";
     }
     return "Bob";
    }
};