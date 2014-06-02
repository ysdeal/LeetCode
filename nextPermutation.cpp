/*
 Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
*/
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void nextPermutation(vector<int> &num) {
     int k = -1;
     int p = -1;

     // find the largest k such that num[k] < num[k+1]
     for(int i = 0; i < num.size()-1; ++i)
     	if(num[i] < num[i+1])
     		k = i;
     // if k does not exist, this is the last sequence. We return its reverse
     if(k < 0) {
      	reverse(num.begin(),num.end());
      	return;
      }
      // find the largest p such that num[p] > num[k]
      for(int i = 0; i < num.size(); ++i)
      	if(num[i] > num[k])
      		p = i;
      // swap them
       swap(num[p],num[k]);
      // reverse the last part of sequence from k + 1
       reverse(num.begin() + k + 1, num.end());
       return;
}

int main(int argc, char const *argv[])
{
	vector<int> num(4,0);
	for(int i = 0; i < 4; i++)
		num[i] = i+1;
	nextPermutation(num);

	for(int i = 0; i < 4; ++i)
		cout << num[i] << " ";
	cout << endl;
	return 0;
}
