class Solution {
public:
    // assign 2 -> newly live
    // assign 3 -> newly dead
    int row[8] = {1,0,-1,0,-1,-1,1,1};
    int col[8] = {0,1,0,-1,-1,1,-1,1};

    bool valid(int r, int c, int m, int n) {
        return r >= 0 && r < m && c >= 0 && c < n;
    }

    int cntLive(vector<vector<int>>& board, int r, int c, int m, int n) {
        int count = 0;
        for(int k = 0; k < 8; k++) {
            int nr = r + row[k];
            int nc = c + col[k];
            if(valid(nr, nc, m, n)) {
                if(board[nr][nc] == 1 || board[nr][nc] == 3) count++;
            }
        }
        return count;
    }
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        for(int r = 0; r < m; r++) {
            for(int c = 0; c < n; c++) {
                int liveNeib = cntLive(board, r, c, m, n);
                if(board[r][c] == 0 && liveNeib == 3) board[r][c] = 2;
                else if(board[r][c] == 1) {
                    if(liveNeib < 2 || liveNeib > 3) board[r][c] = 3;
                }
            }
        }

        for(int r = 0; r < m; r++) {
            for(int c = 0; c < n; c++) {
                if(board[r][c] == 2) board[r][c] = 1;
                else if(board[r][c] == 3) board[r][c] = 0;
            }
        }
    }
};