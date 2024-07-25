class MyStack
{
    queue<int> q;

public:
    MyStack()
    {
    }

    void push(int x)
    {
        int s = q.size();
        q.push(x);
        for (int i = 1; i <= s; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }

    int pop()
    {
        int ele = q.front();
        q.pop();
        return ele;
    }

    int top()
    {
        return q.front();
    }

    bool empty()
    {
        return q.empty();
    }
};