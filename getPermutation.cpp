/*
The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

 1   "123"
 2   "132"
 3   "213"
 4   "231"
 5   "312"
 6   "321"

Given n and k, return the kth permutation sequence.

Note: Given n will be between 1 and 9 inclusive.
*/
#include <vector>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int getPermutation(int n, int k){

   int out = 0;
   int tp = 1;
   std::vector<int> vint(n,0);
   for(int i = 1; i <=n; ++i){
   	  tp *= i;
   	  vint[i-1] = i;
   	  //cout << " " << vint[i];
   }
   k = k - 1;
   for(int ct = 0; ct < n; ++ct){
       tp = tp/(n - ct);
       int id = k/tp;
       //cout << tp << " " << out << " " << vint[id] << " " << id << endl;
       out = out*10 + vint[id];

       //out += string(itoa(v[id]);
       vint.erase(vint.begin() + id);
       k -= id*tp;
   }
   return out;
}

int main(int argc, char const *argv[])
{
	cout << getPermutation(4,11) << endl;
	return 0;
}
