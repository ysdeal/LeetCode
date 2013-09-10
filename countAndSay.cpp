/**
 * The count and say sequence is the sequence of intergers beginning as follows
 * 1, 11, 21, 1211, 111221,...
 * 1 is read off as "one 1" or 11.
 * 11 is read off as "two 1s" or 21.
 *
 * Given an integer n, generate the n^th sequence
 */
string countAndSay(int n){
    if(n==1)
        return "1";

    string s = countAndSay(n-1);
    string out = "";
    string com = "";
    for(int i = 0; i<s.length();){
        char t = s[i];
        int count = 1;
        if(i==s.length()-1){
            out += to_string(count);
            out.push_back(t);
            return out;
        }
        while(s[i+count]==s[i])
            count++;
        out += to_string(count)+s[i];
        i += count;
    }
    return out;
}
