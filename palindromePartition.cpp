/* Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

  [
    ["aa","b"],
    ["a","a","b"]
  ]
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;
void partBack(string, int, vector<vector<string> >&, vector<int>&);
bool isPalindrome(string, int, int);
vector<vector<string> > partition(string s){
	vector<vector<string> > res;
	vector<int> index;
	if(s.length() == 0)
		return res;
	index.push_back(-1);
	partBack(s,0,res,index);
	return res;
}
void partBack(string s, int i, vector<vector<string> > &res, vector<int> &index){
	if(i == s.length()){
		vector<string> v;
		int len = index.size();
		for(int i = 0; i < len; i++){
			v.push_back(s.substr(index[i]+1, index[i+1] - index[i]));
		}
		res.push_back(v);
		return;
	}

	for(int j = i; j < s.length(); j++){
		if(isPalindrome(s, i, j)){
			index.push_back(j);
			partBack(s, j+1, res, index);
			index.pop_back();
		}
	}
}

bool isPalindrome(string s, int i, int j){
	while(i < j){
		if(s[i++] != s[j--])
			return false;
	}
	return true;
}

int main(int argc, char const *argv[])
{
	string s = "aabccdee";
	vector<vector<string> > res = partition(s);
	for(auto &x : res){
		for(auto &y : x)
			cout << y << ",";
		cout << endl;	
	}

	return 0;
}