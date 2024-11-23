// Leetcode Link - https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/
// Maximum Points we can obtain from picking exactly K cards

#include <bits/stdc++.h>
using namespace std;

// Start with initial K size window then add elements from right 
// Time Complexity - O(2*N), Space Complexity - O(1)
class Solution1
{
public:
  int maxScore(vector<int> &cardPoints, int k)
  {
    int lsum = 0, rsum = 0, maxSum = 0;

    // Calculate initial left sum of the first `k` cards.
    for (int i = 0; i < k; i++)
    {
      lsum += cardPoints[i];
    }
    maxSum = lsum; // Initialize maxSum to lsum.

    int rightIndex = cardPoints.size() - 1;

    // Slide the window from the left to the right.
    for (int i = k - 1; i >= 0; i--)
    {
      lsum -= cardPoints[i];             // Remove the current left card.
      rsum += cardPoints[rightIndex];    // Add the current right card.
      rightIndex--;                      // Move the right index.
      maxSum = max(maxSum, lsum + rsum); // Update maxSum.
    }

    return maxSum;
  }
};
