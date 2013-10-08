/**
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/
class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<vector<int>> res;
        vector<int> sol;
        getComb(n, k, 1, sol, res);
        return res;
    }
    void getComb(int n, int k, int l, vector<int> &sol, vector<vector<int>> &res){
        if(sol.size()==k){
            res.push_back(sol);
            return;
        }
        for(int i = l; i <= n; i++){
            sol.push_back(i);
            getComb(n, k, i+1, sol, res);
            sol.pop_back();
        }
    }
};