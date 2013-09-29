/** 
Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.
 */
class Solution {
public:
    int romanToInt(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
     int out = 0;
     int li = 0;
     int ci = 0;
     int n = s.size();
     for(int i = 0; i < n; i++){
         ci = decode(s[i]);
         if(ci > li) out += ci - 2*li;
         if(ci <= li) out += ci;
         li = ci;
     }
     return out;   
    }
private:
    int decode(char t){
        switch(t){
            case 'M': return 1000;
            case 'D': return 500;
            case 'C': return 100;
            case 'L': return 50;
            case 'X': return 10;
            case 'V': return 5;
            case 'I': return 1;
        }
    }
};