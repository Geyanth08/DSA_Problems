// Reference link - https://takeuforward.org/data-structure/find-minimum-number-of-coins/
// Find minimum number of coins or notes required to make the change

#include <bits/stdc++.h>
using namespace std;

// Traversing from last -> Time Complexity - O(N), Space Complexity - O(1)
int main()
{
    vector<int> money = {1, 2, 5, 10, 20, 50, 100, 500, 1000};

    int value;
    cin >> value;

    int count = 0;
    int n = money.size();
    for (int i = n - 1; i > 0; i--)
    {
        if (value >= money[i])
        {
            int temp = value / money[i];
            value -= temp * money[i];
            count += temp;
        }
    }

    cout << count << endl;
}