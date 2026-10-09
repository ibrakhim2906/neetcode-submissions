class Solution {
public:
    bool isValid(string s) {
        if (s.size()%2!=0)
        {
            return false;
        }
        stack<char> stck{};

        for (char& ch : s)
        {
            if (ch == '[' || ch == '{' || ch == '(')
            {
                stck.push(ch);
                continue;
            }

            if (stck.empty())
            {
                return false;
            }

            if (
                (stck.top()=='[' && ch == ']') ||
                (stck.top()=='{' && ch == '}') ||
                (stck.top()=='(' && ch == ')')
            )
            {
                stck.pop();
            } else {
                return false;
            }
        }
        
        return stck.empty();
    }
};