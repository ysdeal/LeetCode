/**
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array. 
*/
class Solution {
public:
    int search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int L = 0;
        int R = n - 1;
        while (L <= R){
            int M = L + (R - L) / 2;
            if(A[M] == target) return M;
            if(A[L] <= A[M]){
                if(A[L] <= target && target < A[M])
                  R = M - 1;
                else
                  L = M + 1;
            } else {
                if(A[M] < target && target <= A[R])
                   L = M + 1;
                else
                   R = M - 1;
            }
        }
        return -1;
    }
};