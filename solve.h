/** 
A region is captured by flipping all 'O's into 'X's in that surrounded region .

For example,

X X X X
X O O X
X X O X
X O X X

After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
 */
class Solution {
public:
    void solve(vector<vector<char>> &board) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int m = board.size();
        if(m==0) return;
        int n = board[0].size();
        for(int i = 0; i < n; i++)
           if(board[0][i] == 'O')
               dfs(0,i,board);
        for(int i = 0; i < m; i++)
           if(board[i][0] == 'O')
              dfs(i,0,board);
        for(int i = 0; i < n; i++)
           if(board[m-1][i] == 'O')
              dfs(m-1, i, board);
        for(int i = 0; i < m; i++)
           if(board[i][n-1] == 'O')
              dfs(i,n-1,board);
        
        for (auto& vec: board)
            for (char& c : vec)
                if (c == 'O')
                    c = 'X';
                else if (c == '+')
                    c = 'O';
        
    }
    void dfs(int i, int j, vector<vector<char>> &board){
        int m = board.size();
        int n = board[0].size();
        if(i<0 || i >= m || j < 0 || j > n || board[i][j]!='O') return;
        
        board[i][j] = '+';
        
        dfs(i-1,j,board);
        dfs(i,j-1,board);
        dfs(i+1,j,board);
        dfs(i,j+1,board);
    }
};