class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> out;
        if(digits.size()==0){out.push_back(1);return out;}
        
        int te=1;
        out = digits;
        for(int i=out.size()-1;i>=0;i--)
        {
            if(out[i]+te==10)
            {
                out[i]=0;
                te = 1;
            }else{
                out[i] += te;
                te=0;
            }
        }
        if (te==1)
          out.insert(out.begin(),1);
        return out;
    }
};