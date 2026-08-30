class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> matching = {
    {')', '('},
    {'}', '{'},
    {']', '['}
     };
        stack<char> s1;
        char c;
        for(int i=0;i<s.length();i++){
            c=s[i];
            if(c=='(' || c=='{' || c=='['){
                s1.push(c);
            }
            else{
                if(s1.empty()){
                    return false;
                }
                if(matching[c]==s1.top()){
                    s1.pop();
                }
                else{
                    return false;
                }
            }
        }
        return s1.empty();
    }
};