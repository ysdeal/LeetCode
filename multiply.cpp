/*
Given two numbers represented as strings, return multiplication of the numbers as a string.
Note: The numbers can be arbitrarily large and are non-negative.
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;
string multiply(string num1, string num2) {
    // Note: The Solution object is instantiated only once and is reused by each test case.
    int n1 = num1.size();
    int n2 = num2.size();
    if((n1==1&&num1[0] =='0') || (n2==1 &&num2[0] == '0'))
      return "0";
    string res(n1 + n2, '0');
    vector<int> re(n1 + n2, 0);
    
    for(int i = 0; i < n1; i++){
        for(int j = 0; j < n2; j++){
            re[i+j+1] += (num1[i] - '0')*(num2[j] - '0');
        }
    }
    
    for(size_t i = n1 + n2 - 1; i > 0; i--){
        if(re[i] > 9)
           re[i-1] += re[i]/10;
        res[i] += re[i]%10;
    }
    res[0] += re[0];
    return res[0]=='0'?string(res.begin()+1,res.end()):res;
}

int main(int argc, char const *argv[])
{
	string num1 = "1234";
	string num2 = "2345";
	cout << multiply(num1,num2);
	return 0;
}
