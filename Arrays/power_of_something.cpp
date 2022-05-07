// Leetcode link - https://leetcode.com/problems/powx-n/
// Find pow(x,n) - x raised to the power n

#include <bits/stdc++.h>
using namespace std;

// Dividing power by 2 and checking -> Time Complexity - O(logN), Space Complexity - O(1)
class Solution
{
public:
    double myPow(double x, int n)
    {
        double ans = 1.0;

        // Edge case when power is negative
        if (n == -2147483648)
        {
            if (x == 1 || x == -1)
            {
                return 1;
            }
            else
                return 0.0;
        }

        long long int nn = n;
        if (nn < 0)
            nn = -1 * n;
        while (nn)
        {
            if (nn % 2)
            {
                ans = ans * x;
                nn -= 1;
            }
            else
            {
                x = x * x;
                nn /= 2;
            }
        }

        if (n < 0)
            return (double)(1.0) / (double)(ans);
        return ans;
    }
};