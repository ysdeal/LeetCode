/**
Given a collection of numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1]. 
 */
class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<vector<int>> ps, lps;
        vector<int> p;
        if(num.size() == 0) {ps.push_back(p);return ps;}
        p.insert(p.begin(), num.begin()+1, num.end());
        lps = permute(p);
        
        for(int i = 0; i < num.size(); i++){
          ps.insert(ps.end(),lps.begin(),lps.end());
          for (int j=0;j<lps.size();j++)
              ps[i*lps.size()+j].insert(ps[i*lps.size()+j].begin()+i,1,num[0]);
        }
        return ps;
    }
};

