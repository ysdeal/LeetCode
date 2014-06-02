/*
 Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.

Below is one possible representation of s1 = "great":

    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t

To scramble the string, we may choose any non-leaf node and swap its two children.

For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".

    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t

We say that "rgeat" is a scrambled string of "great".

Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".

    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a

We say that "rgtae" is a scrambled string of "great".

Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1. 
*/

/*
there exists point that splits s1 and s2, so that these substrings are scambled 
*/
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool isScramble(string s1, string s2){
	int l1 = s1.size();
	int l2 = s2.size();

	if (l1 != l2) return false;
	if (s1 == s2) return true;

    // check whether they consist of same chars
	string st1 = s1, st2 = s2;
	sort(st1.begin(), st1.end());
	sort(st2.begin(), st2.end());
	if (st1 != st2)
		return false;
	for(int i = 1; i < l1; ++i){
		string ss11 = s1.substr(0,i);
		string ss12 = s1.substr(i);

		string ss21 = s2.substr(0, i);
		string ss22 = s2.substr(i);

		if(isScramble(ss11,ss21) && isScramble(ss12, ss22))
			return true;
		ss21 = s2.substr(l1 - i);
		ss22 = s2.substr(0, l1 - i);

		if (isScramble(ss11,ss21) && isScramble(ss12, ss22))
			return true;
	}
    return false;
}

int main(int argc, char const *argv[])
{
	string s1 = "great";
	string s2 = "rgeat";
	cout << isScramble(s1,s2) <<endl;
	return 0;
}