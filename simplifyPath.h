/**
Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"

click to show corner cases.
Corner Cases:

    Did you consider the case where path = "/../"?
    In this case, you should return "/".
    Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
    In this case, you should ignore redundant slashes and return "/home/foo".
*/

class Solution {
public:
    string simplifyPath(string path) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        stack<int> st;
        string p;
        path.append("/");
        st.push(0);
        
        int s = 0;
        for(int i = 1; i < path.size(); i++){
            if(path[i] == '/'){
                if(path[i-1] == '/' || path[i-1] == '.' &&
                (i-2 < 0 || path[i-2] != '.')){
                    s = i;
                }
                else if (path[i-1] == '.' && i-2 >= 0 && path[i-2] == '.'){
                    s = i;
                    if(st.top() == 0) continue;
                    int e = st.top(); st.pop();
                    p.erase(st.top(), e-st.top());
            }
            else{
                p.append(path,s,i-s);
                st.push(p.size());
                s = i;
            }
           }
        }
        return p.size() == 0 ? "/" : p;
    }
};