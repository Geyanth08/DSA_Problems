// Practice link - https://www.codingninjas.com/codestudio/problems/running-median_625409
// You are given a stream of 'N' integers. For every 'i-th' integer added to the running list of integers, print the resulting median.

#include <bits/stdc++.h>
using namespace std;

// Using two heaps -> Time Complexity - O(NlogN), Space Complexity - O(N)
#include <bits/stdc++.h>
void findMedian(int *arr, int n)
{
    if (n == 0)
        return;
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    int median = arr[0];
    maxHeap.push(arr[0]);

    cout << median << " ";

    for (int i = 1; i < n; i++)
    {
        int temp = arr[i];

        if (maxHeap.size() > minHeap.size())
        {
            if (temp < median)
            {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
                maxHeap.push(temp);
            }
            else
                minHeap.push(temp);
            median = (minHeap.top() + maxHeap.top()) / 2;
        }
        else if (maxHeap.size() == minHeap.size())
        {
            if (temp < median)
            {
                maxHeap.push(temp);
                median = maxHeap.top();
            }
            else
            {
                minHeap.push(temp);
                median = minHeap.top();
            }
        }
        else
        {
            if (temp > median)
            {
                maxHeap.push(minHeap.top());
                minHeap.pop();
                minHeap.push(temp);
            }
            else
                maxHeap.push(temp);
            median = (minHeap.top() + maxHeap.top()) / 2;
        }
        cout << median << " ";
    }
}