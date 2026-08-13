class Solution {
public:
int dp[301][301];
int sol(int i,int j,vector<vector<char>>&matrix){
 if(i>=matrix.size()|| j>=matrix[0].size() || matrix[i][j]=='0'){
    return 0;
 }
 if(dp[i][j]!=-1){
    return dp[i][j];
 }
 int right=1+sol(i,j+1,matrix);
 int diag=1+sol(i+1,j+1,matrix);
 int below=1+sol(i+1,j,matrix);
 int temp=min({right,diag,below});
 return dp[i][j]=temp;

}
    int maximalSquare(vector<vector<char>>& matrix) {
        int temp;
        int val=0;
        memset(dp,-1,sizeof(dp));
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[0].size();j++){
            temp=sol(i,j,matrix);
            val=max(val,temp);
        }
    }
        return (val*val);
    }
};