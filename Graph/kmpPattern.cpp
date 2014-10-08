#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

void preProcess(const char *needle, vector<int> &lps){
	int N = strlen(needle);
	int len = 0, i = 1;
	while(i < N){
		if(needle[i] == needle[len])
			lps[i++] = (++len);
		else{
			if(len != 0)
				len = lps[len - 1];
		    else
		    	lps[i++] = 0;
		}
	}
}

vector<int> strMatch(const char *haystack, const char *needle){
    vector<int> res;
    int M = strlen(haystack);
    int N = strlen(needle);
    if(N > M)
        return res;
    if(N == 0){
    	res.push_back(0);
    	return res;
    }

    vector<int> lps(N,0);
    preProcess(needle, lps);
    int i = 0, j = 0;
    while(i < M){
    	if(haystack[i] == needle[j])
    		++i, ++j;
    	if(j == N){
    		res.push_back(i-j);
    		j = lps[j - 1];
    	}else if (haystack[i] != needle[j])
    	    if(j != 0)
    	    	j = lps[j - 1];
    	    else
    	    	i ++;
    }
    return res;
}

int main(int argc, char const *argv[])
{
	char haystack[] = "AABAACAADAABAAABAA";
	char needle[] = "AABA";
	vector<int> res = strMatch(haystack, needle);
	for(auto x : res)
		cout << x << " ";
	return 0;
}
