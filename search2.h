/**
Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Write a function to determine if a given target is in the array. 
*/
class Solution {
public:
    bool search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return searchp(A,0,n-1,target);
    }
private:
   bool searchp(int A[], int s, int e, int target){
       int L = s;
       int R = e;
       while(L <= R){
           int M = (R - L) / 2 + L;
           if(A[M] == target) return true;
            if(A[L] < A[M]){
               if(A[L] <= target && A[M] > target)
                 R = M - 1;
               else
                 L = M + 1;
           } else if(A[M] < A[R]) {
               if(A[M] < target && A[R] >= target)
                 L = M + 1;
               else
                 R = M - 1;
           }else{
               return(searchp(A,L,M-1,target) || searchp(A,M+1,R,target));
           }          
       }
       return false;
   }
};