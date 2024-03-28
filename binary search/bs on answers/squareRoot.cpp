class Solution {
public:
    int mySqrt(int n) {
        int low = 1;
        long long high = n; 
        while (low <= high) {
            long long mid = low + (high - low) / 2; 
            if (mid * mid == n) {
                return mid;
            } else if (mid * mid < n) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return high;
    }
};
