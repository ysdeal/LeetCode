/**
Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,

There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]

The total number of unique paths is 2.

Note: m and n will be at most 100.
*/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        if (obstacleGrid[m-1][n-1] == 1) return 0;
        
        int D[m][n];
        D[0][0] = 0;
        
        bool flag = false;
        for(int i = 0; i < m; i++)
        if(flag || obstacleGrid[i][0]){
            D[i][0] = 0; flag = true;
        }else
            D[i][0] = 1;
        
        flag = false;
        for(int j = 0; j < n; j++)
        if(flag || obstacleGrid[0][j]){
            D[0][j] = 0; flag = true;
        }else
            D[0][j] = 1;
        
        for(int i = 1; i < m; i++)
        for(int j = 1; j < n; j++){
            if(obstacleGrid[i][j]) 
               D[i][j] = 0;
            else
               D[i][j] = D[i-1][j] + D[i][j-1];
        }
        return D[m-1][n-1];
    }
};