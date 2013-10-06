/**
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 */
class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        sort(num.begin(), num.end());
        int n = num.size();
        int diff = INT_MAX;
        int record;
        if(n < 3) return diff;
        
        for(int i = 0; i < n - 2; i++){
            int a = num[i];
            int k = i + 1; 
            int l = n - 1;
            
            while(k < l){
                int tp = a + num[k] + num[l];
                int td = tp - target;
                if(abs(td) < diff) {
                    diff = abs(td);
                    record = tp;
                }
                if(td ==0) return tp;
                if(td > 0) l--;
                else k++;
            }
        }
        return record;
    }
};