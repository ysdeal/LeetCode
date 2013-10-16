/**
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
*/
class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<vector<string>> res;
        string st(n,'.');
        vector<string> board(n,st);
        
        solveNQ(board,0,res);
        return res;
    }
    
    bool isSafe(vector<string>&st, int r, int c){
        int n = st.size();
        for(int i = 0; i < c; i++){
            if(st[r][i] == 'Q')
              return false;
        }
        
        for(int i = r, j = c; i >= 0 && j >= 0; i--, j--){
            if(st[i][j] == 'Q')
               return false;
        }
        
        for(int i = r, j = c; j >= 0 && i < n; i++,j--){
           if(st[i][j] == 'Q')
           return false;
        }
        return true;
    }
    
    bool solveNQ(vector<string> &board, int col, vector<vector<string>> &res){
        int n = board.size();
        if(col >= n){
            res.push_back(board);
            return true;
        }
        
        for(int i = 0; i < n; i++){
            if(isSafe(board, i, col)){
                board[i][col] = 'Q';
                solveNQ(board,col+1, res);
                board[i][col] = '.';
            }
        }
        return false;
    }
};