/** 
Given a set of distinct integers, S, return all possible subsets.

Note:

    Elements in a subset must be in non-descending order.
    The solution set must not contain duplicate subsets.

For example,
If S = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

 */
class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(S.begin(),S.end());
        
        return subP(S);
    }
    vector<vector<int>> subP(vector<int> &S){
        vector<vector<int>> res,lres;
        vector<int> p;
        int n = S.size();
        if(n == 0){res.push_back(p); return res;}
        p.insert(p.begin(), S.begin() + 1, S.end());
        lres = subP(p);
        res.insert(res.begin(),lres.begin(),lres.end());
        for(int i = 0; i < lres.size(); i++){
            vector<int> temp = lres[i];
            temp.insert(temp.begin(),1,S[0]);
            res.push_back(temp);
        }
        return res;
    }
};