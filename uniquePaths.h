/**
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?
*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int D[m][n];
        D[0][0] = 0;
        for(int i = 0; i < m; i++)
        D[i][0] = 1;
        for(int j = 0; j < n; j++)
        D[0][j] = 1;
        
        for(int i = 1; i < m; i++)
        for(int j = 1; j < n; j++)
            D[i][j] = D[i-1][j] + D[i][j-1];
        return D[m-1][n-1];
        
    }
};