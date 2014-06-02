/*
Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true
*/

#include <algorithm>
#include <vector>
#include <cstring>
#include <iostream>

using namespace std;
bool isMatch(char *s, char *p){
	if(*p == '\0') 
		return (*s == '\0');
     
     // if the next character is '*', we just test it
    if(*(p+1) != '*')
        return (*p == *s || (*p == '.' && *s != '\0')) && isMatch(s+1, p+1);
    // next is '*',
    while(*p == *s || (*p == '.' && *s != '\0')){
         if(isMatch(s, p+2)) return true;
         s++;
    }

    return isMatch(s,p+2); 
}

int main(int argc, char const *argv[])
{
	char s[] = "aabc";
	char p[] = ".*";
	if (isMatch(s,p))
		cout << "Matched" << endl;
	else
		cout << "Not Matched" << endl;
	return 0;
}
