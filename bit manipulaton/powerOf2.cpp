// for n-1,we set the rightmost set bit to 0 and remaining right to it as 1
// then perform and (&) operation with original nummber
// this will clear the rightmost set bit (set to 0)
// if equal to 0,then it is a power of 2
bool isPowerOfTwo(int n)
{
    if (n == 0 || n == INT_MIN) // edge case
    {
        return false;
    }
    return ((n & n - 1) == 0);
}