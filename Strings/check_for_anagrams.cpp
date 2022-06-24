// Practice link - https://www.codingninjas.com/codestudio/problems/1172164
// You have been given two strings 'STR1' and 'STR2'. You have to check whether the two strings are anagram to each other or not.
// Two strings are said to be anagram if they contain the same characters, irrespective of the order of the characters.

#include <bits/stdc++.h>
using namespace std;

// Simple Traversal of both strings to count characters -> Time Complexity - O(max(N,M)), Space Complexity - O(1)
bool areAnagram(string &str1, string &str2)
{
    int n = str1.length();
    int m = str2.length();

    vector<int> freq(26, 0);
    for (int i = 0; i < n; i++)
        freq[str1[i] - 'a']++;

    for (int i = 0; i < m; i++)
        freq[str2[i] - 'a']--;

    for (int i = 0; i < 26; i++)
        if (freq[i] > 0)
            return 0;
    return 1;
}