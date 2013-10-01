/**
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]

The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle. 
*/
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = triangle.size();
        if(n==0) return 0;
        if(n==1) return triangle[0][0];
        vector<int> da(n,0);
        da[0] = triangle[0][0];
        for(int i = 1;i < n; i ++){
            vector<int> tp(n,0);
            for(int j = 0; j < i+1; j++){
                if(j==0) tp[j] = da[j] + triangle[i][j];
                else if(j==i)
                     tp[j] = da[j-1] + triangle[i][j];
                else 
                  tp[j] = min(da[j-1],da[j]) + triangle[i][j];
            }
            da = tp;
        }
        int mv = da[0];
        for(int i = 1; i < n; i++)
           if(mv > da[i]) mv = da[i];
        return mv;
    }
};

/* a neat solution */
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {


    int n = triangle.size();
    vector<int> p (n+1, 0);
    while(n-- > 0)
        for(int i = 0; i <= n; ++i) 
            p[i] = triangle[n][i] + ((p[i] < p[i+1])? p[i] : p[i+1]);
    return p[0];
  }
};