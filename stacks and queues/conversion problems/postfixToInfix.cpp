string postToInfix(string s)
{
    stack<string> st;
    int i = 0;
    int n = s.size();
    while (i < n)
    {
        if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))
        {
            string a = "";
            a += s[i];
            st.push(a);
        }
        else
        {
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();
            string conv = '(' + t2 + s[i] + t1 + ')';
            st.push(conv);
        }
        i++;
    }
    return st.top();
}
