// Practice link - https://www.codingninjas.com/codestudio/problems/1062679
// You are given two positive integers N and M. You have to find the Nth root of M i.e. M^(1/N).

double multiply(double num, int n)
{
    double ans = 1.0;
    for (int i = 0; i < n; i++)
    {
        ans *= num;
    }
    return ans;
}

// multiple mid value n times and compare with m -> Time Complexity - O(Nlog(M*10^d)), Space Complexity - O(1)
double findNthRootOfM(int n, long long m)
{
    double low = 1;
    double high = m;
    double eps = 1e-7;

    while ((high - low) > eps)
    {
        double mid = (high + low) / 2.0;
        if (multiply(mid, n) < m)
        {
            low = mid;
        }
        else
        {
            high = mid;
        }
    }

    return low;
}
