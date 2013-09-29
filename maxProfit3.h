/** 
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
 */
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = prices.size();
        if(n <= 1) return 0;
        vector<int> d;
        d.push_back(0);
        int out = 0, dt = 0;
        
        for(int i = 1; i < n; i++)
        {
            dt = prices[i]-prices[i-1] + max(dt,0);
            if(dt > out)
              out = dt;
            d.push_back(out);
        }
        
        out = d[n-1];
        dt = prices[n-1];
        int td = 0;
        for(int i = n-2; i>=0; i--){
            if(dt-prices[i] > td)
               td = dt-prices[i];
               
            if(td + d[i] > out)
              out = td + d[i];
              
            dt = prices[i]>dt? prices[i]: dt;
        }
        return out;
    }
};