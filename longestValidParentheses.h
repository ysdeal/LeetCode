/**
Longest Valid Parentheses 
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
*/
class Solution {
public:
    int longestValidParentheses(string s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int n = s.size();
        int res = 0;
        if(n <= 1) return res;
        
        vector<int> d(n,0);
        for(int i = 1; i < n; i++){
            if(s[i]==')'){
                int id = i - 1 - d[i-1];
                if(id >=0 && s[id] == '('){
                  d[i] = d[i-1] + 2;
                  if(id - 1>=0)
                    d[i] += d[id - 1];
                }
            }
            res = res<d[i]?d[i]:res;
        }
        return res;
    }
};