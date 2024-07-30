string postToPre(string s)
{
    int n = s.size();
    int i = 0;
    stack<string> st;
    while (i < n)
    {
        if (isalnum(s[i]))
        {
            st.push(string(1, s[i]));
        }
        else
        { // operator
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();
            st.push(s[i] + t2 + t1);
        }
        i++;
    }
    return st.top();
}