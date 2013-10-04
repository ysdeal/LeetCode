/**
Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.


*/

class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<vector<bool>> rows(9,vector<bool>(9,false));
        vector<vector<bool>> cols(9,vector<bool>(9,false));
        vector<vector<bool>> blocks(9,vector<bool>(9,false));
        
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j]=='.') continue;
                int c = board[i][j] - '1';
                if(rows[i][c] || cols[j][c] || blocks[i - i % 3 + j / 3][c])
                  return false;
                rows[i][c] = cols[j][c] = blocks[i - i % 3 + j / 3][c] = true;
            }
        }
        return true;
    }
};