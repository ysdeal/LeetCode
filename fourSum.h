/**
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:

    Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
    The solution set must not contain duplicate quadruplets.

    For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

    A solution set is:
    (-1,  0, 0, 1)
    (-2, -1, 1, 2)
    (-2,  0, 0, 2)

 */
class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        sort(num.begin(),num.end());
        vector<vector<int>> res;
        int n = num.size();
        if(n < 4) return res;
        
        for(int i = 0; i < n - 3; i++){
            for(int j = i + 1; j < n - 2; j++){
                for(int k = j + 1; k < n - 1; k++){
                    int val = target - num[i] - num[j] - num[k];
                    int st = k + 1;
                    int ed = n - 1;
                    while(st <= ed){
                        int md = (st + ed) / 2;
                        if(num[md] == val){
                            vector<int> tp;
                            tp.push_back(num[i]);
                            tp.push_back(num[j]);
                            tp.push_back(num[k]);
                            tp.push_back(num[md]);
                            
                            if(find(res.begin(), res.end(), tp) == res.end())
                               res.push_back(tp);
                            break;
                        }
                        if(num[md] > val) ed = md - 1;
                        else st = md + 1;
                    }
                }
            }
        }
        return res;
    }
};