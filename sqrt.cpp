/* compute the int sqrt(int x)
*/

class Solution {

public: int sqrt(int x) {

    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    double x1=x; 
    double x2=x-0.1; 
    double e=0.0001; 
    while(fabs(x2-x1)>e)
    {
        x1=x2; 
        x2=x1-(x1*x1-x)/(2*x1); 
    }
    return int(x2); 
}

};
