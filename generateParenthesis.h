/**
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"
*/
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
    vector<string> res;
    if(n > 0) generator(res,"",0,0,n);
    return res;
    }
    void generator(vector<string>&res,string s, int l, int r, int n){
        if(l==n){
            res.push_back(s.append(n-r,')'));
            return;
        }
        generator(res,s+"(", l+1, r, n);
        if(l>r) generator(res, s+")", l, r+1, n);
    }
};