/**
 Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100". 
*/
class Solution {
public:
    string addBinary(string a, string b) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = a.size()-1;
        int m = b.size()-1;
        string sum="";
        char f = '0';
        while(n>=0 && m >=0){
            if(f=='0'){
                if(a[n]=='1' && b[m] =='1'){
                    f = '1';
                    sum.insert(sum.begin(),'0');
                }else if(a[n]=='1' || b[m] =='1')
                       sum.insert(sum.begin(),'1');
                 else
                      sum.insert(sum.begin(),'0');
            }else{
                if(a[n]=='1' && b[m] =='1'){
                    f = '1';
                    sum.insert(sum.begin(),'1');
                }else if(a[n]=='1' || b[m] =='1'){
                    f = '1';
                    sum.insert(sum.begin(),'0');
                }else{
                    f = '0';
                    sum.insert(sum.begin(),'1');
                }
            }
            n--;
            m--;
        }
        
        while(n>=0){
            if(f=='0') sum.insert(sum.begin(),a[n]);
            else{
                if(a[n]=='1'){
                    f = '1';
                    sum.insert(sum.begin(),'0');
                }else{
                     sum.insert(sum.begin(),'1');
                     f = '0';
                }
            }
            n--;
        }
        
        while(m>=0){
             if(f=='0') sum.insert(sum.begin(),b[m]);
            else{
                if(b[m]=='1'){
                    f = '1';
                    sum.insert(sum.begin(),'0');
                }else{
                     sum.insert(sum.begin(),'1');
                     f = '0';
                }
            }
            m--;           
        }
        
        if(f=='1') sum.insert(sum.begin(),'1');
        return sum;
    }
};

/* neat solution*/
string addBinary(string a, string b) {
// Start typing your C/C++ solution below
// DO NOT write int main() function
string sum="";
int la=a.length()-1;
int lb=b.length()-1;
int c=0;
while (la >=0 || lb >= 0 ||c >0)        
{
    int v = c;
    if (la >=0) v+=a[la]-'0';
    if (lb >=0) v+=b[lb]-'0';

    c = v/2;
    sum = string(1,('0'+(v&1)))+sum;            
    la--;
    lb--;
}
return sum;
}
