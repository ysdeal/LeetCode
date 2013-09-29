/**
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
*/

class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m = grid.size();
        int n = grid[0].size();
        
        int D[m][n];
        D[0][0] = grid[0][0];
        for(int i = 1; i < m; i++ ) D[i][0] = D[i-1][0] + grid[i][0];
        for(int j = 1; j < n; j++ ) D[0][j] = D[0][j-1] + grid[0][j];
        
        for(int i = 1; i < m; i++)
        for(int j = 1; j < n; j++)
        D[i][j] = min(D[i-1][j], D[i][j-1]) + grid[i][j];
        
        return D[m-1][n-1];
        
    }
};