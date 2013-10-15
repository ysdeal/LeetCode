/**
First Missing Positive

Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space. 
 */
class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int i = 0;
        if(n==0) return 1;
        while(i < n){
            if(A[i] >= 0 && A[i] < n && A[A[i]] != A[i])
               swap(A[i],A[A[i]]);
            else
              i++;
        }
        int k = 1;
        while(k < n && A[k] == k) k++;
        if(n == 0 || k < n) return k;
        else return A[0]==k? k+1: k;
    }
};