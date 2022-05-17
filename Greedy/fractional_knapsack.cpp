// GeeksForGeeks link - https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1#
// Given weights and values of N items, we need to put these items in a knapsack of capacity W to get the maximum total value in the knapsack.
// Note - you are allowed to break the item.

#include <bits/stdc++.h>
using namespace std;

struct Item
{
    int value;
    int weight;
};

// Sorting and selecting the items -> Time Complexity - O(NlogN), Space Complexity - O(1)
class Solution
{
public:
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Sorting based upon value/weight
        sort(arr, arr + n, [](const Item &a, const Item &b)
             {
            double r1 = (double)a.value/(double)a.weight;
            double r2 = (double)b.value/(double)b.weight;
            return r1 > r2; });

        int currWeight = 0;
        double max_value = 0.0;

        for (int i = 0; i < n; i++)
        {
            if (currWeight + arr[i].weight <= W)
            {
                currWeight += arr[i].weight;
                max_value += arr[i].value;
            }
            else
            {
                int remaining = W - currWeight;
                max_value += (arr[i].value / (double)arr[i].weight) * (double)remaining;
                break;
            }
        }

        return max_value;
    }
};
