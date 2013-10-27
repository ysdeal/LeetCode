/*
 There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

    Each child must have at least one candy.
    Children with a higher rating get more candies than their neighbors.

What is the minimum candies you must give? 
*/
#include <vector>
#include <iostream>
using namespace std;
int max(int x,int y){ return (x > y)? x:y;}
int candy(vector<int> &ratings){
	int n = ratings.size();
	if(n <= 0) return n;
	vector<int> candy(n,0);
	for(int i = 0, k = 1; i < n; i++){
		if(i >= 1 && ratings[i] > ratings[i-1])
			candy[i] = max(candy[i],k++);
		else
			k = 1;
	}
	for(int j = n - 1, k = 1; j >= 0; j--){
		if(j + 1 < n && ratings[j] > ratings[j+1])
            candy[j] = max(candy[j], k++);
        else
        	k = 1;
	}

	int sum = 0;
	for(int i = 0; i < n; i++)
		sum += candy[i];
	return sum;
}

int main(int argc, char const *argv[])
{
	vector<int> seq = {0,1,2,1,2,3,2,1};

    std::cout << candy(seq) << std::endl;
	return 0;
}