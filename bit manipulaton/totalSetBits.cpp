int countSetBits(int N)
{
    int totalSum = 0;
    for (int i = 1; i <= N; i++)
    {
        int num = i;
        int count = 0;
        while (num != 0)
        {
            num &= (num - 1);
            count++;
        }
        totalSum += count;
    }
    return totalSum;
}
