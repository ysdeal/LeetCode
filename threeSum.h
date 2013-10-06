/**
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

    Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
    The solution set must not contain duplicate triplets.

    For example, given array S = {-1 0 1 2 -1 -4},

    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)

 */
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        sort(num.begin(),num.end());
        vector<vector<int>> res;
        int n = num.size();
        if(n < 3) return res;
        vector<int> tp(3,0);
        for(int i = 0; i < n-2 && num[i]<=0; i++){
            if (i>0 && num[i]==num[i-1]) continue; 
            int a = num[i];
            int k = i + 1;
            int l = n - 1;
            while(k < l){
                int b = num[k];
                int c = num[l];
                int sum = a + b + c;
                if(sum == 0){
                    tp[0]= a;
                    tp[1] = b;
                    tp[2] = c;
                    res.push_back(tp);
                    do{k++;} while(k < l && num[k] == num[k-1]);
                    do{l--;} while(k < l && num[l] == num[l+1]);
                }else if( sum > 0){l --;}
                 else {k ++;}
            }
        }
        return res;
    }
};