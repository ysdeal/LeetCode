/** 
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array A = [1,1,1,2,2,3],

Your function should return length = 5, and A is now [1,1,2,2,3]. 
 */
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n<=1)
          return n;
        int len = 1;
        int ct = 0;
        for(int i = 1; i<n;i++){
            if(A[i]==A[len-1])
            {
                if(ct<1){
                A[len++] = A[i];
                ct ++;}
            }else{
                A[len++] = A[i];
                ct = 0;
            }
        }
        return len;
    }
};