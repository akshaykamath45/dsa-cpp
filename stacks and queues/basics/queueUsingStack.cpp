// approach 1 - when push <<< pop,top
class MyQueue
{
    stack<int> s1, s2;

public:
    MyQueue() {}

    void push(int x)
    {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }

    int pop()
    {
        int ele = s1.top();
        s1.pop();
        return ele;
    }

    int peek() { return s1.top(); }

    bool empty() { return s1.empty(); }
};

// approach 2 - push >>> pop, top
class MyQueue
{
    stack<int> s1, s2;

public:
    MyQueue() {}

    void push(int x) { s1.push(x); }

    int pop()
    {
        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        if (s2.empty())
        {
            return -1;
        }
        int ele = s2.top();
        s2.pop();
        return ele;
    }

    int peek()
    {
        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        if (s2.empty())
        {
            return -1;
        }
        return s2.top();
    }

    bool empty() { return s2.empty() && s1.empty(); }
};
