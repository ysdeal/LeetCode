/**
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
the contiguous subarray [4,−1,2,1] has the largest sum = 6. 
 */
class Solution {
public:
    int maxSubArray(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(n==0) return 0;
        if(n==1) return A[0];
        int d = A[0];
        int rec = A[0];
        
        for(int i = 1; i < n; i++){
            if(rec < 0)
               rec = A[i];
            else
               rec += A[i];
            
            if(rec >= d)
               d = rec;
        }
        
        return d;
    }
};
