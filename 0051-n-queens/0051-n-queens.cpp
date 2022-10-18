class Solution {
public:
    bool isSafe(int row, int col, vector<string> &board, int n) {
        int i = row-1, j = col-1;
        while(i>=0 && j>=0) {
            if(board[i][j]=='Q')
                return false;
            i--, j--;
        }
        i = row, j = col-1;
        while(j>=0) {
            if(board[i][j]=='Q')
                return false;
            j--;
        }
        i=row+1, j = col-1;
        while(i<n && j>=0) {
            if(board[i][j]=='Q')
                return false;
            i++, j--;
        }
        return true;
    }
    
    void solve(int col, vector<string> &board, int n, vector<vector<string>> &ans) {
        if(col==n) {
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++) {
            if(isSafe(row, col, board, n)) {
                board[row][col] = 'Q';
                solve(col+1, board, n, ans);
                board[row][col] = '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        if(n==1)
            return {{"Q"}};
        if(n<4)
            return {};
        vector<vector<string>> ans;
        
        vector<string> board;
        for(int i=0;i<n;i++) {
            string row;
            for(int j=0;j<n;j++)
                row.push_back('.');
            board.push_back(row);
        }
        solve(0, board, n, ans);
        return ans;
    }
};