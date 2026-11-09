class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int i=0;
        int j=0;
        int i1=0;
        int j1=0;
        while(i>=0 && j>=0 &&i<n && j<m && grid[i][j]!='V'){
            if(grid[i][j]=='L'){
                grid[i][j]='V';
                i1=i;
                j1=j;
                j--;
            }
            else if(grid[i][j]=='R'){
                grid[i][j]='V';
                                i1=i;
                j1=j;
                j++;
                
            }
            else if(grid[i][j]=='U'){
                grid[i][j]='V';
                                i1=i;
                j1=j;
             i--;
             
            }
            else if(grid[i][j]=='D'){
                grid[i][j]='V';
                                i1=i;
                j1=j;
                i++;
                
            }
        }
        return {i1,j1};
    }
};