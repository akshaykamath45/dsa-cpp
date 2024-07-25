#include <bits/stdc++.h>
using namespace std;
bool isValid(string s)
{
    stack<char> st;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            st.push(s[i]);
        }
        else if (!st.empty())
        {
            if (st.top() == '(' && s[i] == ')' ||
                st.top() == '{' && s[i] == '}' ||
                st.top() == '[' && s[i] == ']')
            {
                st.pop();
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }

    return st.empty();
}
int minNumber(string s)
{
    stack<char> st;
    int n = s.size();
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
        {
            st.push(s[i]);
        }
        else
        {
            if (!st.empty())
            {
                if (st.top() == '(' && s[i] == ')')
                {
                    st.pop();
                }
            }
            else
            {
                count++;
            }
        }
    }
    // basically the count increases, when stack is empty and we are pushing closing bracket, for which there is no corresponding opening bracket
    // and stack size is for, there is no corresponding closing bracket for the opening bracket present in stack
    cout << "cnt " << count << endl;
    cout << "stack size  " << st.size() << endl;
    return count + st.size();
}

int main()
{
    // string s = "())(()";
    //   string s = "(())()";
    string s = "())(";
    int ans = minNumber(s);
    cout << ans << endl;
    return 0;
}