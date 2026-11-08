class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int totalcount=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
              if(grid[i][j]==1){
                int count=0;
                for(int r=0;r<n;r++){
                    if(r==i)continue;
                    else if(grid[r][j]==1){
                        count++;
                        break;
                    }
                }
                if(count==0){  
                 for(int c=0;c<m;c++){
                    if(c==j)continue;
                    else if(grid[i][c]==1){
                        count++;
                    }
                }
                }  
                if(count>0){
                    totalcount+=1;
                }             
              }
            }
        }
        return totalcount;
    }
};