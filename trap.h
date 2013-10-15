/**
Trapping Rain Water
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
For example,
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. 
In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!
 */
class Solution {
public:
    int trap(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(n<=2) return 0;
        int i = 0; int j = n - 1;
        int water = 0;
        int k = 0;
        while(i < j){
            if(A[i] <= A[j]){
                k = i + 1;
                while(A[i] > A[k]){
                    water += (A[i] - A[k]);
                    k++;
                }
                i = k;
            }else{
                k = j - 1;
                while(A[j] > A[k]){
                    water += (A[j] - A[k]);
                    k --;
                }
                j = k;
            }
            
        }
    
        return water;
    }
};