class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
       int n = matrix.size();
       for (int i=0; i<n/2; i++)
          for(int j = 0; j< (n+1)/2; j++)
           exchange(matrix[i][j],matrix[j][n-i-1], matrix[n-1-i][n-j-1],matrix[n-1-j][i]);
    }
private:
    void exchange(int &a, int &b, int &c, int &d)
    {
        int temp = d;
        d = c;
        c = b;
        b = a;
        a = temp;
    }
};