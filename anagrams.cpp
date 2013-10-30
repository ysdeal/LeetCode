/*
Given an array of strings, return all groups of strings that are anagrams.

Note: All inputs will be in lower-case.
*/
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <iostream>
using namespace std;
vector<string> anagrams(vector<string> &strs) {
    // Note: The Solution object is instantiated only once and is reused by each test case.
    vector<string> res;
    map<string, vector<string> > dict;
    vector<string>::iterator st;
    for(st = strs.begin(); st != strs.end(); st++){
        string key = *st;
        sort(key.begin(),key.end());
        dict[key].push_back(*st);
    }
    map<string,vector<string> >::iterator it;
    for(it = dict.begin(); it != dict.end(); ++it){
        if(it->second.size() > 1){
            for (st = it->second.begin(); st!=it->second.end(); ++st)
               res.push_back(*st);
        }
    }
    return res;
}

int main(int argc, char const *argv[])
{
	vector<string> strs = {"abc", "abelrt", "act", "cat"};
    vector<string> res = anagrams(strs);
    for(auto &x : res)
    	cout << x << " ";
	return 0;
}