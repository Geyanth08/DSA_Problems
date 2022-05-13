// Leetcode link - https://leetcode.com/problems/remove-nth-node-from-end-of-list/
// Remove nth node from the end of the linked list

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

// Using fast and slow pointers -> Time Complexity - O(N), Space Complexity - O(1)
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *start = new ListNode();
        start->next = head;
        ListNode *slow = start;
        ListNode *fast = start;

        // Creating delay
        for (int i = 0; i < n; i++)
            fast = fast->next;

        while (fast->next != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }

        slow->next = slow->next->next;
        return start->next;
    }
};