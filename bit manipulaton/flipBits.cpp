int flipBits(int A, int B)
{
    int ans = A ^ B;
    int count = 0;
    for (int i = 0; i < 31; i++)
    {
        if (ans & (1 << i))
        {
            count += 1;
        }
    }
    return count;
}