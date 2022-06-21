// Practice link - https://www.codingninjas.com/codestudio/problems/implement-trie_631356
// Implement Trie Data Structure to support these operations:
// insert(), search(), startsWith()

#include <bits/stdc++.h>
using namespace std;

/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */
struct Node
{
    Node *links[26];
    bool flag = false;

    // Checks if the reference trie is present or not.
    bool containsKey(char ch)
    {
        return (links[ch - 'a'] != NULL);
    }

    // Creating Reference trie.
    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }

    // To get next node for traversal.
    Node *get(char ch)
    {
        return links[ch - 'a'];
    }

    // Setting flag to true at the end of the Word.
    void setEnd()
    {
        flag = true;
    }

    // Checking whether the word is completed or not.
    bool isEnd()
    {
        return flag;
    }
};

// Time Complexity - O(length of word)
class Trie
{
private:
    Node *root;

public:
    /** Initialize your data structure here. */
    Trie()
    {
        root = new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                return false;
            }
            node = node->get(word[i]);
        }
        return node->isEnd();
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        Node *node = root;
        for (int i = 0; i < prefix.length(); i++)
        {
            if (!node->containsKey(prefix[i]))
            {
                return false;
            }
            node = node->get(prefix[i]);
        }
        return true;
    }
};