/**
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/
class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int>> out;
        if(numRows <= 0) return out;
        for (int i = 0; i < numRows; i ++){
            vector<int> tp;
            tp.push_back(1);
            if(i==0) {out.push_back(tp); continue;}
            if(i==1) {tp.push_back(1); out.push_back(tp); continue;}
            for(int j = 0; j<out[i-1].size()-1;j++)
                  tp.push_back(out[i-1][j]+out[i-1][j+1]);
            tp.push_back(1);
            out.push_back(tp);
        }
        return out;
    }
};