/**
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/
bool isValid(string s) {
stack<char> mys;
int i;
int len = s.size();
for(i=0;i<len;i++){
    if(s[i]=='(') mys.push('(');
    if(s[i]=='{') mys.push('{');
    if(s[i]=='[') mys.push('[');

    if(s[i]==')' && mys.empty() || s[i]==')'&& mys.top()!='(') return false;
    if(s[i]==']' && mys.empty() || s[i]==']'&& mys.top()!='[') return false;
    if(s[i]=='}' && mys.empty() || s[i]=='}'&& mys.top()!='{') return false;

    if(s[i]==')'||s[i]=='}'||s[i]==']') mys.pop();
}
if(mys.empty()) return true;
else return false;
}