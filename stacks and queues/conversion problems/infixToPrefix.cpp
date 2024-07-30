#include <bits/stdc++.h>
using namespace std;

int priority(char ch)
{
    if (ch == '^')
    {
        return 3;
    }
    else if (ch == '*' || ch == '/')
    {
        return 2;
    }
    else if (ch == '+' || ch == '-')
    {
        return 1;
    }
    return -1;
}
string infixToPrefix(string s)
{
    reverse(s.begin(), s.end());
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            s[i] = ')';
        }
        else if (s[i] == ')')
        {
            s[i] = '(';
        }
    }
    int n = s.size();
    int i = 0;
    stack<int> st;
    string ans;
    while (i < n)
    {
        if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))
        {
            ans += s[i];
        }
        else if (s[i] == '(')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                ans += st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            if (s[i] == '^')
            {
                while (!st.empty() && priority(s[i]) <= priority(st.top()))
                {
                    ans += st.top();
                    st.pop();
                }
            }
            else
            {
                while (!st.empty() && priority(s[i]) < priority(st.top()))
                {
                    ans += st.top();
                    st.pop();
                }
            }

            st.push(s[i]);
        }
        i++;
    }
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    string s = "(A+B)*C-D+F";
    string ans = infixToPrefix(s);
    cout << ans << endl;

    return 0;
}