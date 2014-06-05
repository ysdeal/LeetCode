/*
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter) 
*/

#include <algorithm>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

void helper(string s, string rIp, int st, int brk, vector<string> &res){
    
    if(s.size() - st > (4 - brk)*3)
    	return;
    if(s.size() - st < 4 - brk)
    	return;

    if(brk >= 4 && st == s.size()){
    	rIp.resize(rIp.size() - 1);
    	res.push_back(rIp);
    	return;
    }
    int num = 0;
    for(int i = st; i < st + 3; ++i){
       num = num*10 + (s[i] - '0');
       if(num <= 255){
       	 rIp += s[i];
       	 helper(s, rIp+".", i + 1, brk+1, res);
       }
       if(num == 0)
       	  break;
    }

}

vector<string> restoreIpAddresses(string s){
	vector<string> res;
	if (s.size() > 12 || s.size() == 0)
	   return res;

    string rIp;
    int brk = 0;
    helper(s, rIp, 0, brk,res);
    return res;
}

int main(int argc, char const *argv[])
{
	string s = "0000";
	vector<string> rs = restoreIpAddresses(s);
	for(auto &x : rs)
	cout << x <<endl;
	return 0;
}