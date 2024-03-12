// using left shift
bool isKthBitSet(int n, int k)
{
    return (n & (1 << (k - 1))) != 0;
}

// using right shift
bool isKthBitSet(int n, int k)
{
    return (n >> k - 1 & 1) != 0;
}