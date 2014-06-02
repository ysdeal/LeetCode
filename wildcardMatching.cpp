/*
Implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "*") → true
isMatch("aa", "a*") → true
isMatch("ab", "?*") → true
isMatch("aab", "c*a*b") → false
*/

#include <algorithm>
#include <vector>
#include <cstring>
#include <iostream>

using namespace std;
bool isMatch(const char *s, const char *p){
    const char* star = NULL;
    const char* ss = s;
    while(*s){
    	cout << *p << " " << *s <<endl;
    	if(*p == '?' || *p == *s){
    		s++;
    		p++;
    		continue;
    	}
    	if(*p == '*'){
    		star = p++;
    		ss = s;
    		cout << "star appears" << endl;
    		continue;
    	}
    	if(star){
    		cout << "move back" << endl;
    		p = star + 1;
    		s = ++ss;
            continue;
    	}
    }
    while(*p == '*')
    	p++;

    return !*p;
}  

int main(int argc, char const *argv[])
{
	//char s[] = "abdefeabc";
	char s[] = "aa";
	char p[] = "a";
	if (isMatch(s,p))
		cout << "Matched" << endl;
	else
		cout << "Not Matched" << endl;
	int i = 0;
	int b = ++i;
	int c = i++;
	cout << b << " " << i << " " << c << endl;
	return 0;
}