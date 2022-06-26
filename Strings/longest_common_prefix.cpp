// Practice link - https://www.codingninjas.com/codestudio/problems/2090383
// You are given an array ‘ARR’ consisting of ‘N’ strings. Your task is to find the longest common prefix among all these strings.

#include <bits/stdc++.h>
using namespace std;

// checking each character of every word for smallest word length times -> Time Complexity - O(M*N), Space Complexity - O(1)
string longestCommonPrefix(vector<string> &arr, int n)
{
    int minLength = arr[0].length();
    for (int i = 1; i < n; i++)
    {
        if (minLength > arr[i].length())
            minLength = arr[i].length();
    }

    string prefix = "";
    for (int i = 0; i < minLength; i++)
    {
        char wordLetter = arr[0][i];
        for (int j = 1; j < n; j++)
        {
            if (arr[j][i] != wordLetter)
                return prefix;
        }
        prefix.push_back(wordLetter);
    }
    return prefix;
}
