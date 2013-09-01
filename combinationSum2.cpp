class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
    vector<vector<int>> out;
    sort(num.begin(),num.end());
    
    for(int i=0;i<num.size() && num[i]<=target;i++){
        
        if(i>0&& num[i]==num[i-1])
          continue;
        
        int n = num[i];
        int sub = target - n;
        if (sub==0){
            vector<int> tp;
            tp.push_back(n);
            out.push_back(tp);
        }else if(sub>0){
            vector<int> newNum(num.begin()+i+1, num.end());
            vector<vector<int>> rp = combinationSum2(newNum,sub);
            for(int j = 0; j<rp.size();j++){
                rp[j].insert(rp[j].begin(),n);
                out.push_back(rp[j]);
            }
        }
        
    }
    return out;
    
    }
};