/**
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

 */
class Solution {
public:
    int numTrees(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<int> d(n+1,0);
        if(n <= 1) return n;
        d[0] = 0;
        d[1] = 1;
        for(int i = 2; i <= n; i++){
           d[i] = 2*d[i-1];
           for (int j = 1; j <= i; j++)
           d[i] += d[j-1] * d[i-j];
        }
        return d[n];  
    }
};