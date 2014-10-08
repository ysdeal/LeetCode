#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

struct TrieNode{
	bool leaf;
	unordered_map<char, TrieNode*> children;
	TrieNode():leaf(false),children(){}
};

class Trie{
private:
	TrieNode *root;
	bool deleteWordUtil(string s, TrieNode *r, int cur);
	void autoCompleteUtil(TrieNode *r, string &sol, vector<string> &res);
public:
	Trie():root(new TrieNode()){}
	~Trie(){deleteTrie(root);}
	void addWord(string s);
	bool searchWord(string s);
	void deleteWord(string s);
	void deleteTrie(TrieNode *root);
    vector<string> autoComplete(string s);
    //To avoid shallow copy, you may need to give
    //copy constructor and overload assignment operator
    Trie(const Trie&);
    Trie& operator=(const Trie&);
};

void Trie::addWord(string s){
	cout << "Insert: " << (s.empty()?"empty string":s) << endl;
	TrieNode *cur = this->root;
	for(auto x : s){
		if(cur->children.count(x) == 0)
			cur->children[x] = new TrieNode();
		cur = cur->children[x];
	}
	cur->leaf = true;	
}

bool Trie::searchWord(string s){
	cout << "Search: " << (s.empty()?"empty string":s) << endl;
	if(this->root == nullptr)
		return false;
	TrieNode *cur = this->root;
	for(auto x : s){
		if(cur->children.count(x) == 0)
			return false;
		cur = cur->children[x];
	}
	return cur->leaf;
}

void Trie::deleteWord(string s){
     cout << "Delete: " << (s.empty()?"empty string":s) << endl;
     if(root == nullptr)
     	return;
     if(s.empty()){
     	cout << "Deleting node: empty string" << endl;
     	root->leaf = false;
     }
     deleteWordUtil(s, root, 0);
}

bool Trie::deleteWordUtil(string s, TrieNode *r, int cur){
	if(cur < s.size())
		cout << "\tGo deep: "<< s[cur] << endl; 
	if(r == nullptr)
		return false;
	if(cur == s.size()){ //base case
		r->leaf = false; // unmark the leaf
		if(r->children.size() != 0) // if s is a prefix of other string
			return false;
		return true;
	}else{
		if(r->children.count(s[cur]) == 0) // if cannot find s
			return false;
		if(deleteWordUtil(s, r->children[s[cur]], cur + 1)){
			//delete eligible nodes
			cout << "\tDeleting node: "<< s[cur] << endl;
			delete r->children[s[cur]];
			r->children.erase(s[cur]);
			//recursively climb up, and delete eligible nodes
			return r->children.empty() && r->leaf == false;
		}
		return false;
	}
}

void Trie::deleteTrie(TrieNode *r){
	if(r == nullptr)
		return;
	for(auto it = r->children.begin(); it != r->children.end(); ++it)
		deleteTrie(it->second);
	delete r;
	r = nullptr;
}

vector<string> Trie::autoComplete(string s){
    vector<string> res;
    if(this->root == nullptr)
        return res;
    TrieNode *cur = this->root;
    for(auto x : s){
    	if(cur->children.count(x) == 0)
    		return res;
    	cur = cur->children[x];
    }
    string sol = s;
    autoCompleteUtil(cur, sol, res);
    return res;
}

void Trie::autoCompleteUtil(TrieNode *r, string &sol, vector<string> &res){
    if(r == nullptr)
    	return;
    if(r->leaf == true)
    	res.push_back(sol);

    int len = sol.size();
    for(auto it = r->children.begin(); it != r->children.end(); ++it){
    	sol.append(1, it->first);
    	autoCompleteUtil(it->second, sol, res);
    	sol.resize(len);
    }

}

int main(int argc, char const *argv[])
{
	Trie t = Trie();
	t.addWord("");
	t.addWord("Hello");
	t.addWord("Balloon");

    if (t.searchWord("Hell"))
        cout << "Found Hell" << endl;
    if (t.searchWord("Hello"))
        cout << "Found Hello" << endl;
    if (t.searchWord("Helloo"))
        cout << "Found Helloo" << endl;
    if (t.searchWord("Ball"))
        cout << "Found Ball" << endl;
    if (t.searchWord("Balloon"))
        cout << "Found Balloon" << endl;
    if (t.searchWord(""))
        cout << "Found empty string" << endl;
 
    t.deleteWord("Balloon");
    if (t.searchWord("Balloon"))
        cout << "Found Balloon" << endl;
         
    t.addWord("Balloon");
    t.addWord("Ball");
 
    t.deleteWord("Balloon");
    t.deleteWord("");
    if (t.searchWord(""))
        cout << "Found empty string" << endl;

    cout << "Test Auto Complete..................." <<endl;
    t.addWord("Balloon");
    t.addWord("Ballz");
    t.addWord("Ballabc");
    t.addWord("Balzabc");
    t.addWord("BalloonHaHa");
    vector<string> dict = t.autoComplete("Ball");
    for(auto x : dict)
    	cout << x << " ";
    cout << endl;
    return 0;
}