// Count number of subarrays whose XOR is K

#include <bits/stdc++.h>
using namespace std;

// Function Declaration
int countSubarrays(vector<int> &v, int target);

int main()
{

    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int target;
    cin >> target;

    int total_subarrays = countSubarrays(v, target);

    cout << total_subarrays << endl;

    return 0;
}

// Using Hashmap (To store previous xor) -> Time Complexity - O(NlogN), Space Complexity - O(N)
int countSubarrays(vector<int> &v, int target)
{
    unordered_map<int, int> mp;

    int cnt = 0;
    int xorr = 0;

    for (auto i : v)
    {
        xorr = xorr ^ i;

        if (xorr == target)
        {
            cnt++;
        }

        // y^k = XR then y = XR^k
        if (mp.find(xorr ^ target) != mp.end())
        {
            cnt += mp[xorr ^ target];
        }

        mp[xorr] += 1;
    }

    return cnt;
}