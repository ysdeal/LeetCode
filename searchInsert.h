/**
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0 
*/
class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int L = 0;
        int R = n - 1;
        if(A[0] > target) return 0;
        if(A[n-1] < target) return n;
        while(L <= R){
            int M = L + (R - L) / 2;
            if(A[M] == target) return M;
            if(A[M] > target)
               R = M - 1;
            else
               L = M + 1;
        }
        return (R+L)/2 + (R+L)%2;
    }
};