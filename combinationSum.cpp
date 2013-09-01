class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int>> out;
        sort(candidates.begin(), candidates.end());
        
        for (int i = 0; i< candidates.size() && candidates[i]<=target;i++)
        {
            int tp = candidates[i];
            int sub = target - tp;
            if(sub == 0)
            {
                vector<int> tv;
                tv.push_back(tp);
                out.push_back(tv);
                return out;
            }else if(sub > 0)
            {
              vector<int> newCan(candidates.begin()+i,candidates.end());
              vector<vector<int>> rp = combinationSum(newCan, sub);
              for(int j = 0; j<rp.size();j++){
                  rp[j].insert(rp[j].begin(),tp);
                  out.push_back(rp[j]);
              }
            }
            
        }
        return out;
    }
};