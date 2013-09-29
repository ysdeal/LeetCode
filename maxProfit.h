/** 
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one
share of the stock), design an algorithm to find the maximum profit.
 */
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = prices.size();
        int d = 0;
        int out = 0;
        if(n<=1) return 0;
        for(int i = 1;i < n; i++){
            d = prices[i]-prices[i-1] + max(d,0);
            if (d > out)
               out = d;
        }
        return out;
    }
};