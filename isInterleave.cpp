/*
Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

For example,
Given:
s1 = "aabcc",
s2 = "dbbca",

When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false. 
*/
#include <algorithm>
#include <vector>
#include <cstring>
#include <iostream>

using namespace std;
bool isIterleave(string s1, string s2, string s3){
	int n1 = s1.size();
	int n2 = s2.size();
	int n3 = s3.size();

	if(n1 + n2 != n3) return false;
	vector<vector<bool>> D(n1+1, vector<bool>(n2 + 1, false));
	D[0][0] = 1;
    for(int i = 0; i < n2; ++i){
    	if(s2[i] != s3[i])
    		break;
    	D[0][i+1] = true;
    }

    for(int i = 0; i < n1; ++i){
    	if(s1[i] != s3[i])
    		break;
    	D[i+1][0] = true;
    }    


	for(int i = 1; i <= n1; ++i)
		for(int j = 1; j <= n2; ++j){
			if(s1[i-1] == s3[i+j-1] && s3[i+j-1] != s2[j-1])
				D[i][j] = D[i-1][j];
            else if(s1[i-1] != s3[i+j-1] && s3[i+j-1] == s2[j-1])
            	D[i][j] = D[i][j-1];
            else if(s1[i-1] == s3[i+j-1] && s3[i+j-1] == s2[j-1])
            	D[i][j] = (D[i][j-1] || D[i-1][j]);
		}
    return D[n1][n2];
}

int main(int argc, char const *argv[])
{
	string s1 = "aabcc";
	string s2 = "dbbca";
	string s3 = "aadbbcbcac";
	cout << isIterleave(s1,s2,s3) << endl;
	return 0;
}