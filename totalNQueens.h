/** 
Follow up for N-Queens problem.

Now, instead outputting board configurations, return the total number of distinct solutions.
 */
class Solution {
public:
    int totalNQueens(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int res = 0;
        int* board =new int[n]; 
        solveNQ(board,0,n,res);
        delete[] board;
        return res;
    }
    
    void solveNQ(int *A, int col, int n, int& res){
        if(col >= n){
            res++;
            return;
        }
        for(int i = 0; i < n; i++){
            A[col] = i;
            if(isSafe(A,col))
                solveNQ(A,col+1,n,res);
        }
    }
    
    bool isSafe(int *A, int col){
        for(int i = 0; i < col; i++){
            if(A[i] == A[col] || abs(A[i] - A[col]) == col - i)
            return false;
        }
        return true;
    }
};