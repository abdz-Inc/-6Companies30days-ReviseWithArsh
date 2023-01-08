class Solution {
public:

    int arith(int l, int r, char s)
    {
        // cout<<l<<" "<<s<<" "<<r<<endl;
        if(s == '+')
        {
            
            return l+r;
        }
        else if(s == '-')
        {
            return l-r;
        }
        else if(s == '*')
        {
            return l*r;
        }
        else if(s == '/')
        {
            return l/r;
        }

        return -1;

    }

    bool isnum(string s)
    {
        for(int i = 0;i<s.length();i++)
        {
            if(s.length() > 1 && i == 0){
                if(s[i] == '-')
                {
                    continue;
                }
            }
            if(isdigit(s[i]) == 0)
            {
                return false;
            }
        }
        return true;
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(int i = 0;i<tokens.size();i++)
        {
            if(isnum(tokens[i]))
            {
                // cout<<"here"<<endl;
                st.push(stoi(tokens[i]));
            }
            else
            {
                // cout<<"else here"<<endl;
                // cout<<st.top()<<" ";
                int r = st.top();
                st.pop();
                // cout<<st.top()<<endl;
                int l = st.top();
                st.pop();
                int res = arith(l,r,tokens[i][0]);
                // cout<<res<<endl;
                st.push(res);
            }
        }
        // cout<<"Answer is : "<<st.top()<<endl;
        return st.top();
    }
};
