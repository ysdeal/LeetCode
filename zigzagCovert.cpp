/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R

And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);

convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR". 
*/
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <iostream>
using namespace std;

string convert(string s, int nRows){
    int n = s.size();
    if (n <= nRows || nRows == 1) return s;
    int in = 2*nRows - 2;
    string res = "";
    
    for(int r = 0; r < nRows; ++r){
        for(int j = 0; j < n/in + 1; ++j){
            int id = j*in + r;
            if(id <= n - 1) 
                res += s[id];
            if(r == 0 || r == nRows-1)
               continue;
            else{
                cout << id << " " << id - 2*r + in << endl;
                if (id - 2*r + in <= n-1)
                    res += s[id - 2*r + in];
            }
        }
    }
    return res;
}

int main(int argc, char const *argv[])
{
    string s = "ABC";
    cout << convert(s, 2) << endl;
    return 0;
}