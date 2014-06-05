/*
You are given a string, S, and a list of words, L, that are all of the same length. Find all starting indices of substring(s) in S that is a concatenation of each word in L exactly once and without any intervening characters.

For example, given:
S: "barfoothefoobarman"
L: ["foo", "bar"]

You should return the indices: [0,9].
(order does not matter). 
*/

#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <iostream>
#include <unordered_map>

using namespace std;

vector<int> findSubstring(string s, vector<string> &L){
   vector<int> res;
   int n = L.size();
   if (n <= 0 || s.size() < n*L[0].size())
   	 return res;
   	int m = L[0].size();
    
    unordered_map<string,int> Lwords;
    unordered_map<string, int> Cwords;
    for(int i = 0; i < n; ++i)
    	++Lwords[L[i]];

    for(int i = 0; i < s.size() - m*n+1; ++i){
    	if(!Cwords.empty())
    	   Cwords.clear();
    	int j = 0;
    	for(j = 0; j < n; ++j){
            string tp = s.substr(i+j*m, m);
            if(Lwords.find(tp) == Lwords.end())
            	break;
            ++Cwords[tp];
            if(Cwords[tp] > Lwords[tp])
            	break;
    	}
        if (j == n) res.push_back(i);
    }
    return res;
}

int main(int argc, char const *argv[])
{
	vector<string> L = {"foo", "bar"};
	string s = "barfoothefoobarmanbarfoobarfoo";
	vector<int> bp = findSubstring(s,L);
	for(auto &x : bp)
		cout << x <<" ";
	cout << endl; 
	return 0;
}