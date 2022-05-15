// Leetcode link - https://leetcode.com/problems/rotate-list/
// Given head of the linked list, rotate the list to the right by k places

#include <bits/stdc++.h>
using namespace std;

// Creating a Node
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Traversing K % len Nodes -> Time Complexity - O(N), Space Complexity - O(1)
class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head or !head->next or k == 0)
            return head;

        ListNode *curr = head;
        int len = 1;
        while (curr->next and ++len)
        {
            curr = curr->next;
        }

        curr->next = head;
        k = k % len;
        k = len - k;
        while (k--)
            curr = curr->next;

        head = curr->next;
        curr->next = NULL;

        return head;
    }
};