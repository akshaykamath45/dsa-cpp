#include <bits/stdc++.h>
using namespace std;

string clearDigits(string s)
{
    // doesn't passes all test cases
    // string ans = s;
    // for (int i = 0; i < s.size(); i++)
    // {
    //     if (isdigit(s[i]))
    //     {
    //         ans = "";
    //     }
    // }
    // return ans;
    stack<char> st;
    for (char c : s)
    {
        if (isdigit(c))
        {

            while (!st.empty() && isalpha(st.top()))
            {
                st.pop();
                break;
            }
        }
        else
        {
            st.push(c);
        }
    }

    string result = "";
    while (!st.empty())
    {
        result = st.top() + result;
        st.pop();
    }
    return result;
}
int main()
{
    string s = "cb34";
    // abc cb34
    string ans = clearDigits(s);
    cout << "ans " << ans << endl;
    return 0;
}