/**
For example,
Given n = 3,
You should return the following matrix:

[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]

*/
class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<vector<int>> res(n,vector<int>(n));
        int s = 1;
        generate(res,n,0,s);
        return res;
    }
    
    void generate(vector<vector<int>> &mat, int n, int k, int &s){
        if(n<=0) return;
        if(n == 1) mat[k][k]=s++;
        
        for(int i = 0; i < n - 1; i++)
            mat[k][k+i] = s++;
        for(int i = 0; i < n - 1; i++)
           mat[k+i][k+n-1] = s++;
        for(int i = 0; i < n - 1; i++)   
           mat[k+n-1][k+n-1-i] = s++;
        for(int i = 0; i < n - 1; i++)   
           mat[k+n-1-i][k] = s++;
       generate(mat, n-2, k+1, s);  
    }
};