/**
Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character '.'.

You may assume that there will be only one unique solution. 
*/

class Solution {
public:
    bool solveSudoku(vector<vector<char> > &board) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        pair<int,int> ei = findEmpty(board);;
        if(ei.first == -1 || ei.second == -1) return true;
        for (int i = 0; i < 9; i++){
            board[ei.first][ei.second] = i + '0';
            if(isValidBoard(board, ei) && solveSudoku(board))
              return true;
            board[ei.first][ei.second] = '.';
        }
        return false;
    }
private:
    bool isValid(const vector<char>& vec) {
        vector<bool> occur(9, false);
        for (int i = 0; i < 9; ++i) {
            if (isdigit(vec[i])) {
                if (occur[vec[i]-'1']) return false;
                else occur[vec[i]-'1'] = true;
            }
        }
        return true;
    }

    bool isValidBoard(const vector< vector<char> >& board, pair<int, int> pos) {

        if (!isValid(board[pos.first])) return false;

        vector<char> column(9);
        for (int i = 0; i < 9; ++i)
            column[i] = board[i][pos.second];
        if (!isValid(column)) return false;

        int block_row = pos.first / 3;
        int block_col = pos.second / 3;
        vector<char> block;
        for (int i = block_row * 3; i < block_row * 3 + 3; ++i)
            for (int j = block_col * 3; j < block_col * 3 + 3; ++j)
                block.push_back(board[i][j]);
        if (!isValid(block)) return false;

        return true;
    }
    
    pair<int,int> findEmpty(vector<vector<char> > &board){
        for(int i = 0; i < 9; ++i)
           for(int j = 0; j < 9; ++j)
              if(board[i][j] == '.') return make_pair(i,j);
        return make_pair(-1,-1);
    }
};