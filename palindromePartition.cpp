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
#include <climits>
using namespace std;
void partBack(string, int, vector<vector<string> >&, vector<int>&);
bool isPalindrome(string, int, int);
int mincut(string);
int min (int a, int b) { return (a < b)? a : b; }
int mincut(string s){
	int n = s.length();
	int L[n][n];
	bool P[n][n];
	for(int i = 0; i < n; i++){
		L[i][i] = 0;
		P[i][i] = true;
	}

	for(int len = 2; len <= n; len++){
		for(int i = 0; i < n - len + 1; i++){
			int j = i + len -1;
			if(len == 2)
				P[i][j] = (s[i] == s[j]);
			else
				P[i][j] = (s[i] == s[j]) && P[i+1][j-1];
		    if(P[i][j])
		    	L[i][j] = 0;
		    else{
		    	L[i][j] = INT_MAX;
		    	for(int k = i; k < j; k++)
		    		L[i][j] = min(L[i][j], L[i][k] + L[k+1][j] + 1);
		    }
		}
	}
	return L[0][n-1];
}



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
    cout << mincut(s) << endl;
	return 0;
}