/**
Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.

Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

 */
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<string> numtochar;
        vector<string> res;
        numtochar.push_back(string(" "));
        numtochar.push_back(string(""));
        numtochar.push_back(string("abc"));
        numtochar.push_back(string("def"));
        numtochar.push_back(string("ghi"));
        numtochar.push_back(string("jkl"));
        numtochar.push_back(string("mno"));
        numtochar.push_back(string("pqrs"));
        numtochar.push_back(string("tuv"));
        numtochar.push_back(string("wxyz"));
        return letter(digits,0,numtochar);
    }
    vector<string> letter(string &dig, int s, vector<string> &nums){
        vector<string> res, lres;
        int n = dig.size();
        if(s == n){
            res.push_back(string(""));
            return res;
        }
        
        lres = letter(dig, s+1, nums);
        int t = dig[s] - '0';
        if(t==1) return lres;
        
        string tp = nums[t];
        for(int i = 0; i < tp.size(); i++){
           for(int j = 0; j < lres.size(); j++){
               string tz = lres[j];
               tz.insert(tz.begin(),tp[i]);
               res.push_back(tz);
           }   
        }
        return res;
    }
};