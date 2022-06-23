// Practice link - https://www.codingninjas.com/codestudio/problems/number-of-distinct-substring_1465938
// Calculate the number of distinct substrings in the ‘WORD’.

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *links[26];

    bool containsKey(char ch)
    {
        return (links[ch - 'a'] != NULL);
    }

    Node *get(char ch)
    {
        return links[ch - 'a'];
    }

    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }
};

// Traversing all possibilities -> Time Complexity - O(N^2), Space Complexity - O(N^2)
int distinctSubstring(string &word)
{
    Node *root = new Node();
    int count = 0;
    int n = word.length();

    for (int i = 0; i < n; i++)
    {
        Node *node = root;
        for (int j = i; j < n; j++)
        {
            if (!node->containsKey(word[j]))
            {
                node->put(word[j], new Node());
                count++;
            }
            node = node->get(word[j]);
        }
    }
    return count;
}
