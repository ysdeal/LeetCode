/**
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example,
Given s = "Hello World",
return 5. 
*/
class Solution {
public:
    int lengthOfLastWord(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = 0;
        bool sp = false;
        for(int i = 0; i<strlen(s); i++){
            if(s[i]!=' '){
                if(sp)
                   len = 0;
                len++;
                sp = false;
            }
            else sp = true;
        }
        return len;
    }
};