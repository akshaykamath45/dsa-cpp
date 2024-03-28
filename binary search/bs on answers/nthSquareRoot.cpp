// to calculate the power
// if ans==m return 1
// if ans> m return 2
// if ans<m return 0

// we are doing this manually to prevent the overflow case,instead of calculating direct power
int func(int mid, int n, int m)
{
    long long ans = 1;
    for (int i = 1; i <= n; i++)
    {
        ans = ans * mid;
        if (ans > m)
            return 2;
    }
    if (ans == m)
        return 1;
    return 0;
}

int NthRoot(int n, int m)
{
    long long low = 0;
    long long high = m;
    while (low <= high)
    {
        long long mid = low + (high - low) / 2;
        long long midN = func(mid, n, m);
        if (midN == 1)
        {
            return mid;
        }
        else if (midN == 0)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}