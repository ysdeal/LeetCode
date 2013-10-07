/**
 Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[1,1,2], [1,2,1], and [2,1,1]. 
 */
class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<vector<int>> res;
        sort(num.begin(),num.end());
        doPermute(num, 0, res);
        return res;
    }
    void doPermute(vector<int> &num, int s, vector<vector<int>> &res){
        if(s == num.size()){res.push_back(num); return;}
        unordered_set<int> used;
        for(int i = s; i < num.size(); i++){
            if(used.find(num[i]) == used.end()){
                swap(num[s],num[i]);
                doPermute(num, s+1, res);
                swap(num[s],num[i]);
                used.insert(num[i]);
            }
        }
    }
};

