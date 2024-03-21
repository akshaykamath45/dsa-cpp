// brute force : using directly xor
int findXOR(int L, int R)
{
    int xorr = 0;
    for (int i = L; i <= R; i++)
    {
        xorr ^= i;
    }
    return xorr;
}

// optimal: discovering the pattern
int func(int N){
    if(N%4==1) return 1;
    else if (N%4==2) return N+1;
    else if(N%4==3) return 0;
    else return N;
}
int findXOR(int L, int R){
    int N=L-1;
    int ans=0;
    int part1=func(N);
    int part2=func(R);
    ans=part1^part2;
    return ans;    
} 