/**
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]

You should return [1,2,3,6,9,8,7,4,5]. 
*/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<int> res;
        int m = matrix.size();
        if(m==0) return res;
        
        int n = matrix[0].size();
        spiralO(matrix, m,n,0, res);
        return res;
    }
    void spiralO(vector<vector<int> > &mat, int m, int n, int k, vector<int> &res){
        if (m <= 0 || n <= 0)
              return;
        if (m == 1) {
           for (int j = 0; j < n; j++)
            res.push_back(mat[k][k+j]);
           return;
         }
        if (n == 1) {
           for (int i = 0; i < m; i++)
            res.push_back(mat[k+i][k]);
           return;
        }
        for (int j = 0; j < n - 1; j++)
           res.push_back(mat[k][k+j]);
 
        for (int i = 0; i < m - 1; i++)
           res.push_back(mat[k+i][k+n-1]);
  
        for (int j = 0; j < n - 1; j++)
           res.push_back(mat[k+m-1][k+n-1-j]);
  
        for (int i = 0; i < m - 1; i++)
           res.push_back(mat[k+m-1-i][k]);
 
        spiralO(mat, m-2, n-2, k+1, res);
    }
};