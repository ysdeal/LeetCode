/** 
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like 
(ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions
 at the same time (ie, you must sell the stock before you buy again).
 */
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = prices.size();
        int D[2] = {0};
        if(n<=1) return 0;
        for(int i = 1;i < n; i++){
            D[i%2] = max(prices[i]-prices[i-1],0) + D[(i-1)%2];
        }
        return D[(n-1)%2];       
    }
};