class Solution {
public:
bool dfs(vector<vector<int>>& grid,int i,int j,int &n,int &m){
    if(i<0 || i>=n || j<0 || j>=m){
        return false;
    }
    if(grid[i][j]==1){
        return true;
    }
    grid[i][j]=1;
    bool left=dfs(grid,i,j-1,n,m);
    bool right=dfs(grid,i,j+1,n,m);
    bool top=dfs(grid,i-1,j,n,m);
    bool bottom=dfs(grid,i+1,j,n,m);
    if(left==true && right==true && top==true && bottom== true){
        return true;
    }
    return false;

}
    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){  
                if(dfs(grid,i,j,n,m)){
                    count++;
                }
                }
            }
        }
        return count;
    }
};