/*Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"

Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T, return the emtpy string "".

If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S. 
*/

/* Idea
   1. use two tables to record the number of chars in T to be found, and found
   2. two points
*/

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <climits>

using namespace std;

string minWindow(string S, string T) {
    int sn = S.size();
    int tn = T.size();
    if(tn > sn) return "";
    
    int needToFound[256] = {0};
    int Filled[256]      = {0};
    
    int subwin = INT_MAX;
    
    int count = 0;
    for(int i = 0; i < tn; ++i)
       needToFound[T[i]] ++;
    int wb = 0;
    for(int bg =0, pos = 0; pos < sn; ++pos){
        if(needToFound[S[pos]] == 0) continue;
        Filled[S[pos]] ++;
        
        if(Filled[S[pos]] <= needToFound[S[pos]])
           count ++;

        if(count == tn){
            while(Filled[S[bg]] == 0 || Filled[S[bg]] > needToFound[S[bg]]){
                if(Filled[S[bg]] > needToFound[S[bg]])
                   Filled[S[bg]] --;
                bg++;
            }             
            if(subwin > pos - bg + 1){
            	subwin = pos - bg + 1;
            	wb = bg;
            }
        }
    }
    if(count < tn) 
       return "";
    else
       return S.substr(wb,subwin);
}

int main(int argc, char const *argv[])
{
	string S = "ABC";
	string T = "B";

	cout << minWindow(S,T) <<endl;
	return 0;
}