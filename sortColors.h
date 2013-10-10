/**
Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note:
You are not suppose to use the library's sort function for this problem.

click to show follow up.

Follow up:
A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.

Could you come up with an one-pass algorithm using only constant space?
*/

class Solution {
public:
    inline void swap(int &a, int &b){
        int temp = a;
        a = b;
        b = temp;
    }
    void sortColors(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int l = 0;
        int r = n-1;
        int p = 0;
        while(p<=r){
            if(A[p]==0){
                if(p>l)
                  swap(A[l++],A[p]);
                else{
                  ++p;
                  ++l;
                }
            }else if(A[p] == 2){
                if(p < r)
                   swap(A[r--], A[p]);
                else
                   return;
            }else
               ++p;
        }
    }
};