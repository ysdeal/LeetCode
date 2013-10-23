/*
Given a string, find the length of the longest substring without repeating characters. 
For example, the longest substring without repeating letters for "abcabcbb" is "abc", 
which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
      int n = s.length( );
      int i = 0, j = 0;
      int res = 0;
      bool exist[256] = {false};
      while(j < n){
          if(exist[s[j]]){
              res = max(res, j - i);
             while(s[i] != s[j]){
                 exist[s[i]] = false;
                 i++;
             }
             i++;
             j++;
          }else{
              exist[s[j]] = true;
              j++;
          }
      }
      return max(res,n-i);
    }
};