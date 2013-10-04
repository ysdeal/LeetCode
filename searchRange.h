/**
Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4]. 
*/
class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<int> range(2,-1);
        int lb = 0;
        int ub = n;
        
        while(lb < ub){
            int m = (ub + lb) / 2;
            if(A[m] < target)
              lb = m + 1;
            else
              ub = m;
        }
        
        if(A[lb]!= target) return range;
        range[0] = lb;
        ub = n;
        while(lb < ub){
            int m = (ub + lb) / 2;
            if(A[m] > target)
              ub = m;
            else
              lb = m + 1;
        }
        range[1] = ub - 1;
        return range;
    }
};