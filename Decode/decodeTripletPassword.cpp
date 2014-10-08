#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <set>
#include <random>

using namespace std;
default_random_engine generator;

bool everyTripFound(vector<string> &setList, string head){
	for (int id = 0; id < setList.size(); ++id){
		bool found = true;
		for (int i = 0; i < head.size() - 2; ++i)
		    for (int j = i + 1; j < head.size() - 1; ++j)
		        for (int k = j + 1; k < head.size(); ++k)
				if (setList[id][0] == head[i] && setList[id][1] == head[j]
					&& setList[id][2] == head[k]){
					found = false;
					break;
				}
	    if (found) return false;
	}
	return true;
}

string tripletRandomPick(string orgPwd){
	int len = orgPwd.size();
	if (len == 3)
		return orgPwd;
	string res = "";
	set<int> idx;
	uniform_int_distribution<int> distribution(0, len - 1);
	while (idx.size() < 3){
		int id = distribution(generator);
		if (idx.find(id) == idx.end())
			idx.emplace(id);
	}
	for (auto it = idx.begin(); it != idx.end(); ++it)
		res += string(1, orgPwd[*it]);
	return res;
}

void dfsDecode(string head, int n, vector<string> &setList, vector<string> &res){
	if (head.size() == n){
		if (everyTripFound(setList,head))
		    res.push_back(head);
		return;
	}

	for (int i = 0; i < setList.size(); ++i){
		if (head == ""){
			string headstr = setList[i];
			dfsDecode(headstr, n, setList, res);
		}else{
			if (head.substr(head.size() - 2) == setList[i].substr(0, 2)){
				cout << head + ": " + head.substr(head.size() - 2) + ", next:" + setList[i] <<endl;
				string headNext = head + string(1, setList[i][2]);
				dfsDecode(headNext, n, setList, res);
			}
		}
	}
}

int main(int argc, char const *argv[]){
	cout << "This is Decode Triplet Password program" << endl;
	cout << "Please input the original Password:";
	string orgPwd = "";
	cin >> orgPwd;
	cout << "Password is :" << orgPwd << endl;

	// create 
	unordered_map<string, int> tripSets;
	vector<string> setList;
	for (int i = 0; i < 3000; ++i){
		string tmp = tripletRandomPick(orgPwd);
		if (tripSets.find(tmp) == tripSets.end())
			setList.push_back(tmp);
		tripSets[tmp] ++;
	}

	cout << "The size of triplet set (unique) is " << setList.size() << endl;
	for (auto x : setList)
		cout << x << ", " << tripSets[x] << endl;

	vector<string> guessStrList;
	string head = "";
	dfsDecode(head, orgPwd.size(),setList, guessStrList);

	cout << "After DFS Decoding, the guesses are:" << endl;
	for (auto x : guessStrList)
		cout << x << ", ";
	cout << "........" << endl;
	int zd = 0;
	cin >>zd;
	return 0;
}
