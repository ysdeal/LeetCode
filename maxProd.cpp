#include <algorithm>
#include <iostream>
#define max(a,b) (a > b)? a:b

int maxProduct(int A[], int n){
	if ( n == 0)
		return 0;
	int res = A[0];
	int minEnd = 1, maxEnd = 1;
	for(int i = 0; i < n; ++i){
        if(A[i] > 0){
        	maxEnd *= A[i];
        	minEnd = (minEnd < 0)? minEnd*A[i] : 1;
        	res = max(maxEnd, res);
        }else if(A[i] < 0){
        	int tmax = minEnd * A[i];
        	minEnd = maxEnd * A[i];
        	maxEnd = (tmax > 0) ? tmax : 1;
        	res = max(tmax, res);
        }else{
        	maxEnd = minEnd = 1;
        	res = max(res, 0);
        }
	}
	return res;
}

int main(int argc, char const *argv[])
{
	int A[] = {-2, 2, 3, -2};
	std::cout << maxProduct(A, 4) << std::endl;
	return 0;
}