// Practice Link - https://www.geeksforgeeks.org/problems/floor-in-a-sorted-array-1587115620/1
// Lower Bound - smallest index such that arr[ind] >= n (given number)

#include <bits/stdc++.h>
using namespace std;

// Using Binary Search - Time Complexity - O(logN)
int method1(vector<int> &v, int target)
{
  int n = v.size();
  int ans = n, low = 0, high = n - 1;
  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    if (v[mid] >= target)
    {
      ans = mid;
      high = mid - 1;
    }
    else
    {
      low = mid + 1;
    }
  }

  // return the index 
  return ans;
}

// Using lower_bound(begin, end, value)
int method2(vector<int> &v, int target){
  return lower_bound(v.begin(), v.end(), target) - v.begin();
}

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

  cout << "Index is: " << method2(v, target);
}