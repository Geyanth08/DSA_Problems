// Practice link - https://www.geeksforgeeks.org/problems/second-largest3735/1
// Find the second largest element in the array

#include <bits/stdc++.h>
using namespace std;

// Using Sorting --> Time Complexity - O(NlogN), Space Complexity - O(1)
class Solution1
{
public:
  int getSecondLargest(vector<int> &arr)
  {
    int n = arr.size();

    // Sort the array in ascending order.
    sort(arr.begin(), arr.end());

    // Traverse the array from the second-to-last element.
    for (int i = n - 2; i >= 0; i--)
    {
      // If the current element is not equal to the largest element.
      if (arr[i] != arr[n - 1])
        return arr[i]; // Return the second largest element.
    }

    // If all elements are the same, return -1.
    return -1;
  }
};

// Using Two Pass Search --> Time Complexity - O(N), Space Complexity - O(1)
class Solution2
{
public:
  int getSecondLargest(vector<int> &arr)
  {
    int maxi = arr[0]; // Initialize the maximum value.

    // Find the largest element in the array.
    for (int i = 1; i < arr.size(); i++)
    {
      maxi = max(arr[i], maxi);
    }

    int sec_maxi = -1; // Initialize the second largest value.

    // Find the largest element that's not equal to `maxi`.
    for (int i = 0; i < arr.size(); i++)
    {
      if (arr[i] != maxi) // Ignore the largest value.
      {
        sec_maxi = max(sec_maxi, arr[i]); // Update the second largest value.
      }
    }

    return sec_maxi; // Return the second largest value.
  }
};

// Using one Pass --> Time Complexity - O(N), Space Complexity - O(1)
class Solution3
{
public:
  int getSecondLargest(vector<int> &arr)
  {
    int maxi = -1, sec_maxi = -1; // Initialize variables for the largest and second largest.

    for (int i = 0; i < arr.size(); i++)
    {
      // If the current element is greater than the largest value.
      if (maxi < arr[i])
      {
        sec_maxi = maxi; // Update second largest before changing the largest.
        maxi = arr[i];   // Update the largest value.
      }
      // If the current element is smaller than the largest but larger than the second largest.
      else if (arr[i] != maxi && sec_maxi < arr[i])
      {
        sec_maxi = arr[i]; // Update the second largest value.
      }
    }

    return sec_maxi; // Return the second largest value.
  }
};
