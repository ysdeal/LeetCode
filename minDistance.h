/**
Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character
*/

class Solution {
public:
    int minDistance(string word1, string word2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int l1 = word1.size();
        int l2 = word2.size();
        int D[l1+1][l2+1];
        
        for(int i = 0; i<=l1;i++)
           D[i][0]=i;
        for(int j = 0; j<=l2; j++)
           D[0][j] = j;
           
        for(int i=1; i<=l1; i++)
           for(int j = 1; j<=l2; j++){
              int diff = 0;
              if(word1[i-1] != word2[j-1])
                diff = 1;
              D[i][j] = min(D[i][j-1], D[i-1][j]) + 1;
              D[i][j] = min(D[i][j], D[i-1][j-1]+diff);
           }
       return D[l1][l2];
    }
};