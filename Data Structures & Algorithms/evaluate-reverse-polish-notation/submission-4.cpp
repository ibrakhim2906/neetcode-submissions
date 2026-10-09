class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stck{};

        for (int i = 0; i<tokens.size(); i++)
        {
            string s = tokens[i];
            if (s=="+" || s=="-" || s=="*" || s=="/")
            {
                int n2 = stck.top(); stck.pop();
                int n1 = stck.top(); stck.pop();
                int res;

                if (s=="+")
                {
                    res = n1+n2;
                }
                if (s=="-")
                {
                    res = n1-n2;
                }
                if (s=="*")
                {
                    res = n1*n2;
                }
                if (s=="/")
                {
                    res = n1/n2;
                }

                stck.push(res);
            } else {
                stck.push(stoi(tokens[i]));
            }

        }

        return stck.top();
        
    }
};