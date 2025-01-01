// Leetcode link - https://leetcode.com/problems/remove-outermost-parentheses/
// Remove the outermost parenthese of each and every primitive strings of main string
// Input: (()())(())
// Output: ()()()

#include <bits/stdc++.h>
using namespace std;

// If we get equal number of right and left brackets then it can form a primitive string
// Time Complexity - O(2N), Space Complexity - O(N)
class Solution1
{
public:
  string removeOuterParentheses(string s)
  {
    int l = 0, r = 0;   // Pointers to mark the beginning (l) and end (r) of the current primitive substring.
    int lb = 0, rb = 0; // Counters for left '(' and right ')' parentheses in the current substring.
    vector<string> str; // To store the primitive substrings.
    string ans = "";    // The final result string after removing outer parentheses.

    // Traverse the input string `s` using the right pointer.
    while (r < s.size())
    {
      if ('(' == s[r])
        lb++; // Increment left parenthesis count for '('.
      else
        rb++; // Increment right parenthesis count for ')'.

      // If the counts of '(' and ')' are equal, we found a primitive substring.
      if (lb == rb)
      {
        str.push_back(s.substr(l, r - l + 1)); // Extract the substring and store it.
        l = r + 1;                             // Move the left pointer to the start of the next substring.
      }
      r++; // Increment the right pointer.
    }

    // Process each primitive substring to remove its outer parentheses.
    for (auto it : str)
    {
      if (it.size() >= 2)
      {
        ans += it.substr(1, it.size() - 2); // Append the substring without the first and last character.
      }
    }

    return ans; // Return the final result.
  }
};

// Increment and Decrement based on right and left brackets 
// Time Complexity - O(N), Space Complexity - O(1)
class Solution2
{
public:
  string removeOuterParentheses(string s)
  {
    string ans = ""; // To store the final result
    int balance = 0; // Keeps track of the current balance of parentheses

    // Traverse the string
    for (char c : s)
    {
      if (c == '(')
      {
        // Add to result only if it's not the outermost '('
        if (balance > 0)
          ans += c;
        balance++; // Increment balance for '('
      }
      else
      {
        balance--; // Decrement balance for ')'
        // Add to result only if it's not the outermost ')'
        if (balance > 0)
          ans += c;
      }
    }

    return ans;
  }
};
