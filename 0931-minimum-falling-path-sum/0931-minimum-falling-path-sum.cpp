class Solution {
public:
int dp[101][101];
bool visited[101][101];
int solve(vector<vector<int>>&matrix,int &n,int i,int j){
    if(i>=n || j>=n || i<0 ||  j<0){
        return INT_MAX;
    }
    if(i==n-1){
        return matrix[i][j];
    }

      if (visited[i][j]) {
            return dp[i][j];
        }
            visited[i][j] = true;
    int a=solve(matrix,n,i+1,j);
    int b=solve(matrix,n,i+1,j-1);

int c=min(a,b);
return dp[i][j]=matrix[i][j]+min(c,solve(matrix,n,i+1,j+1));
}
    int minFallingPathSum(vector<vector<int>>& matrix) {
     
      int n=matrix.size();
      int ans=INT_MAX;
      for(int i=0;i<n;i++){   
      ans=  min(solve(matrix,n,0,i),ans);
      }
      return ans;
    }
};