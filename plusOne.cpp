class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(digits.size()==0){digits.push_back(1);return digits;}
        
        int te=1;
        for(int i=digits.size()-1;i>=0;i--)
        {
            if(digits[i]+te==10)
            {
                digits[i]=0;
                te = 1;
            }else{
                digits[i] += te;
                return digits;
            }
        }
        if (te==1)
          digits.insert(digits.begin(),1);
        return digits;
    }
};