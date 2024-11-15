// Practice link - https://www.naukri.com/code360/problems/ceiling-in-a-sorted-array_1825401
// Find Floor and ceil of a given number
// Floor - largest index less than or equal to target (arr[ind] <= x)
// Ceil - smallest indes greater than or equal to target (arr[ind] >= x) --- similar to lower_bound

#include <bits/stdc++.h>
using namespace std;

// Finding floor using binary search - Time COmplexity - O(logN)
int find_floor(vector<int> &a, int n, int x)
{
  int ans = -1;
  int low = 0, high = n - 1;

  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    if (a[mid] <= x)
    {
      ans = a[mid];
      low = mid + 1;
    }
    else
    {
      high = mid - 1;
    }
  }
  return ans;
}

pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x)
{
  int ceil_ind = -1;
  int floor_num = -1;
  int ceil_num;

  // get the index (if element not present then it returns n)
  ceil_ind = lower_bound(a.begin(), a.end(), x) - a.begin();
  floor_num = find_floor(a, n, x);

  if (ceil_num == n)
    ceil_num = -1;
  else
    ceil_num = a[ceil_num];

  return {floor_num, ceil_num};
}