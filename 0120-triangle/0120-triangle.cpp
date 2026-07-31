class Solution {
public:

    int minimumTotal(vector<vector<int>>& triangle) {
   vector<vector<int>>t=triangle;
for(int row=triangle.size()-2;row>=0;row--){
    for(int col=0;col<=row;col++){
        t[row][col]=t[row][col]+min(t[row+1][col],t[row+1][col+1]);
    }
}
return t[0][0];
    }
};