/**
Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space? 
*/
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> tp;
        if(rowIndex < 0) return tp;
        tp.push_back(1);
        if(rowIndex == 0) return tp;
        tp.push_back(1);
        if(rowIndex == 1) return tp;
        
        int t1,t2;
        for(int i = 2; i <= rowIndex; i ++){
            t2 = 1;
            for(int j = 1; j < i; j ++){
                t1 = t2;
                t2 = tp[j];
                tp[j] = t1 + t2;
            }
            tp.push_back(1);
        }
        return tp;
    }
};