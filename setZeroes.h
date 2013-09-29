/**
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

click to show follow up.
Follow up:

Did you use extra space?
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?

*/

class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m = matrix.size();
        if(!m) return;
        int n = matrix[0].size();
        
        int frow = 1;
        int fcol = 1;
        for(int i = 0; i < m; i++) if(!matrix[i][0]) {fcol = 0; break;}
        for(int j = 0; j < n; j++) if (!matrix[0][j]) {frow = 0; break;}
        for(int i = 1; i < m; i++)
           for(int j = 1; j < n; j++)
             if(!matrix[i][j]){
                 matrix[0][j] = 0;
                 matrix[i][0] = 0;
             }
        for(int i = 1; i < m; i++){
            if(!matrix[i][0])
              for(int j = 1; j < n; j++)
              matrix[i][j] = 0;
        }
        
        for(int j = 1; j < n; j++){
            if(!matrix[0][j])
              for(int i = 1; i < m; i++)
              matrix[i][j] = 0;
        }
        
        for(int i = 0; i < m; i++) matrix[i][0] *= fcol;
        for(int j = 0; j < n; j++) matrix[0][j] *= frow;
        return;
    }
};