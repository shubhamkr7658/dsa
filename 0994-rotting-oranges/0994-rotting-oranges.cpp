class Solution {
public:
queue<pair<int,int>>que;
int fresh=0;
int bfs(vector<vector<int>>&grid){
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[i].size();j++){
            if(grid[i][j]==2){
           que.push({i,j});
            }
            if(grid[i][j]==1){
                fresh++;
            }
        }
    }
if(que.empty()){
    return 0;
}
 int count=0;
 while(!(que.empty())){
    int n=que.size();
    while(n--){
        int i=que.front().first;
        int j=que.front().second;
        que.pop();
        if(i-1>=0 && grid[i-1][j]==1){
            grid[i-1][j]=2;
            fresh--;
         que.push({i-1,j});
        }
        if(j-1>=0 && grid[i][j-1]==1){
            fresh--;
            grid[i][j-1]=2;
            que.push({i,j-1});
        }
        if(i+1<grid.size()&& grid[i+1][j]==1){
            fresh--;
            grid[i+1][j]=2;
            que.push({i+1,j});
        }
        if(j+1<grid[i].size() && grid[i][j+1]==1){
            fresh--;
            grid[i][j+1]=2;
            que.push({i,j+1});
        }

    }
    count++;
 }
 return count-1;
}
    int orangesRotting(vector<vector<int>>& grid) {
      int ans= bfs(grid);
      if(fresh==0){
        return ans;
      }
      return -1;
    }
};