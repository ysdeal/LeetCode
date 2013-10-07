/**
The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2
 */
class Solution {
public:
    vector<int> grayCode(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<int> res, lres;
        if(n==0) { res.push_back(0); return res;}
        lres = grayCode(n - 1);
        res.insert(res.begin(), lres.begin(), lres.end());
        for(int i = lres.size()-1; i>=0; i--){
           res.push_back(lres[i] + (1 << (n-1)));
        }
        return res;
    }
};

