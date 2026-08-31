class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        string c;
       
        for(int i=0;i<tokens.size();i++){
            string token=tokens[i];
            if(token=="+" || token=="-" || token=="*" || token=="/"){
               
                int b=s.top();
                s.pop();
                int a=s.top();
                s.pop();
                if (token == "+") s.push(a + b);
                else if (token == "-") s.push(a - b);
                else if (token == "*") s.push(a * b);
                else if (token == "/") s.push(a / b);

            }
            else{
                s.push(stoi(token));
            }

        }
        return s.top();
    }
};
