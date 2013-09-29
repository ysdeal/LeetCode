/** 
Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.
 */
class Solution {
public:
    string intToRoman(int num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        string sym[] = {"M","CM","D","CD","C","XC","L","XL","X", "IX","V","IV","I"};
        int symi[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        int i = 0;
        string out;
        for(int i = 0; i < 13; i++){
            while(num >= symi[i]){
                out.append(sym[i]);
                num -= symi[i];
            }
        }
        return out;
    }
};