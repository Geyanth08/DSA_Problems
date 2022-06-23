// Practice link - https://www.codingninjas.com/codestudio/problems/maximum-xor_3119012
// Find the maximum XOR of two numbers from a given array

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *links[2];

    bool containsKey(int ind)
    {
        return (links[ind] != NULL);
    }

    Node *get(int ind)
    {
        return links[ind];
    }

    void put(int ind, Node *node)
    {
        links[ind] = node;
    }
};

class Trie
{
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(int num)
    {
        Node *node = root;

        for (int i = 31; i >= 0; i--)
        {
            // Get the ith index bit of a number.
            int bit = (num >> i) & 1;
            if (!node->containsKey(bit))
            {
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }

    int findMax(int num)
    {
        Node *node = root;
        int maxNum = 0;

        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if (node->containsKey(!bit))
            {
                maxNum = maxNum | (1 << i);
                node = node->get(!bit);
            }
            else
            {
                node = node->get(bit);
            }
        }
        return maxNum;
    }
};

// Find maximum XOR value with each of the element in the array -> Time Complexity - O(N*32) + O(M*32), Space Complexity - O(N*32)
int maximumXor(vector<int> A)
{
    Trie trie;
    int n = A.size();
    for (int i = 0; i < n; i++)
    {
        trie.insert(A[i]);
    }
    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, trie.findMax(A[i]));
    }
    return maxi;
}