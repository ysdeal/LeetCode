/**
 Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome. 
*/
class Solution {
public:
    bool isPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = s.size();
        if(n<=1) return true;
        int l = 0;
        int r = n - 1;
        
        while(l < r){
            if(!isAlph(s[l])){
                l++;
                continue;
            }
            if(!isAlph(s[r])){
                r--;
                continue;
            }           
            
            if(s[l] == s[r] || s[l] == s[r] + 32 || s[r] == s[l] + 32){
                l++;
                r--;
            } else 
              return false;
    
        }
        return true;
    }
private:
   bool isAlph(char c){
       return (c >= 'a' && c<= 'z') || (c >= 'A' && c <= 'Z') || (c>= '0' && c<= '9');
   }
};