#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void rearrage(vector<int> &arr){
	int n = arr.size();
	int i = -1;
	for(int j = 0; j < n; ++j)
		if(arr[j] < 0)
			swap(arr[++i],arr[j]);
	int pos = i + 1, neg = 0;
	while(pos < n && neg < pos && arr[neg] < 0){
		swap(arr[neg], arr[pos]);
		pos++;
		neg += 2;
	}
}

void rightrotate(vector<int> &arr, int outofspace, int cur){
	int tmp = arr[cur];
	for(int i = cur; i > outofspace; i--)
		arr[i] = arr[i-1];
	arr[outofspace] = tmp;
}

void rearrage2(std::vector<int> &arr){
	int outofspace = -1;
	for(int id = 0; id < n; id++){
		if(outofspace >= 0)
           if (((arr[id] >= 0) && (arr[outofplace] < 0))
                || ((arr[id] < 0) && (arr[outofplace] >= 0))){
           	   if(id - outofplace > 2)
           	   	   outofplace += 2;
           	   	else
           	   		outofplace = 1;
           }

        if(outofplace == -1){
        	if (((arr[id] >= 0) && (!(id & 0x01)))
                || ((arr[id] < 0) && (id & 0x01)))
                outofplace = id;
        }
	}
}

int main(int argc, char const *argv[])
{
	vector<int> arr = {-1, 2, -3, 4, 5, 6, -7, 8, 9};
	rearrage(arr);
	for(auto x : arr)
		cout << x << " ";
	return 0;
}