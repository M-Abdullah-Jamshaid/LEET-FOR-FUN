class Solution
{
public:
    bool isValid(string s)
    {
        int size = s.size();
        stack<char> st;
        st.push(s[0]);
        for (int i = 1; i < size; i++)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                st.push(s[i]);
            }
            else
            {
                if(s[i] == ')'){
                    if(!st.empty()&&st.top() == '('){
                        st.pop();
                    }
                    else{
                        return false;
                    }
                }
                else if(s[i] == ']'){
                    if(!st.empty()&&st.top() == '['){
                        st.pop();
                    }
                    else{
                        return false;
                    }
                }
                else{
                    if(!st.empty()&&st.top() == '{'){
                        st.pop();
                    }
                    else{
                        return false;
                    }
                }
            }
        }
        return st.empty();
    }
};