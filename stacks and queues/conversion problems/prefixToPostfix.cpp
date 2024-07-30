string preToPost(string s)
{
    int n = s.size();
    int i = n - 1;
    stack<string> st;
    while (i >= 0)
    {
        if (isalnum(s[i]))
        {
            st.push(string(1, s[i]));
        }
        else
        {
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();
            st.push(t1 + t2 + s[i]);
        }
        i--;
    }
    return st.top();
}