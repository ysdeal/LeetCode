/**
Write a function to find the longest common prefix string amongst an array of strings. 
 */
class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (strs.empty()) return "";
        int ridx = strs[0].size();
        for(int i = 1; i < strs.size(); i++){
            for(int j = 0; j < ridx; j++){
                if(strs[i][j] != strs[0][j])
                   ridx = j;
            }
        }
        return strs[0].substr(0,ridx);
    }
};