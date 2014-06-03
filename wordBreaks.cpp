//This include word break and word break II
/* Word break
 Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code". 
*/

#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <unordered_set>
using namespace std;

bool wordBreak(string s, unordered_set<string> &dict){
   vector<bool> D(s.size()+1, false);
   D[0] = true;
   for(int i = 1; i < s.size()+1; ++i){
   	  for(int j = i - 1; j>=0; --j){
   	  	if(D[j] && dict.find(s.substr(j, i-j)) != dict.end()){
   	  		D[i] = true;
   	  		break;
   	  	}
   	  }
   }
   return D[s.size()];
}


// subroutine of word break two
void wbrecur(string s, unordered_set<string> &dict, int st, vector<int> &idx, vector<bool>& red, vector<string> &res){
	if(st == s.size()){
       string tp;
       for(int i = 0; i < idx.size() - 1; ++i){
       	tp += s.substr(idx[i]+1, idx[i+1]-idx[i]);
       	if (i != idx.size()-2)
       		tp += " ";
       }
       res.push_back(tp);
       return;
	}

    for(int i = st; i < s.size(); ++i){
    	int md = res.size();
    	if(dict.find(s.substr(st, i - st + 1)) != dict.end() && red[i+1]){
    		idx.push_back(i);
    		wbrecur(s,dict, i+1, idx, red,res);
    		idx.pop_back();
    		// the last part cannot be broken
    		if (md == res.size())
                red[i+1] = false;
    	}
    }
}


// word break 2 
// combined with DP
// add one more array to record whether i to n can be broken
vector<string> wordBreakII(string s, unordered_set<string> &dict){
	vector<string> res;
	vector<int> idx(1,-1);
	vector<bool> red(s.size()+1,true);
	wbrecur(s, dict, 0, idx, red, res);
	return res;
}

int main(int argc, char const *argv[])
{
	unordered_set<string> dict={"cat", "cats", "and", "sand", "dog"};
	string s = "catsanddog";
	if (wordBreak(s,dict))
	   cout << "Broken" << endl;
	else
		cout << "Not broken" << endl;

	vector<string> wb2 = wordBreakII(s,dict);
	cout << wb2.size() << endl;
	for(int i = 0; i < wb2.size(); ++i)
		cout << wb2[i] << endl;
	return 0;
}

