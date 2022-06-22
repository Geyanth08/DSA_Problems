// Practice link - https://www.codingninjas.com/codestudio/problems/complete-string_2687860
// Find longest complete string.

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *links[26];
    bool flag = false;

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

    void setEnd()
    {
        flag = true;
    }

    bool isEnd()
    {
        return flag;
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

    bool checkIfPrefixExists(string word)
    {
        bool f = true;
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (node->containsKey(word[i]))
            {
                node = node->get(word[i]);
                f = f & node->isEnd();
            }
            else
            {
                return false;
            }
        }
        return f;
    }
};

string completeString(int n, vector<string> &a)
{
    Trie *obj = new Trie();
    for (auto word : a)
        obj->insert(word);

    string longest = "";

    for (auto it : a)
    {
        if (obj->checkIfPrefixExists(it))
        {
            if (it.length() > longest.length())
                longest = it;
            else if (it.length() == longest.length() and it < longest)
                longest = it;
        }
    }

    if (longest == "")
        return "None";
    return longest;
}