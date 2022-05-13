// Leetcode link - https://leetcode.com/problems/delete-node-in-a-linked-list/
// Given the node to be deleted

#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// By Simply swapping the data with next node -> Time Complexity - O(1), Space Complexity - O(1)
class Solution
{
public:
    void deleteNode(ListNode *node)
    {

        node->val = node->next->val;
        node->next = node->next->next;
    }
};