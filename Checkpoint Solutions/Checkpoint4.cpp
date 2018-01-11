/* Problem Statement
Given a singly linked list, modify the value of **first half nodes** such that : 

* 1st node’s new value =  the last node’s value - first node’s current value  
* 2nd node’s new value = the second last node’s value - 2nd node’s current value, 

and so on ...

> **NOTE :** 
> * If the length L of linked list is odd, then the first half implies at first floor(L/2) nodes. So, if L = 5, the first half refers to first 2 nodes. 
> * If the length L of linked list is even, then the first half implies at first L/2 nodes. So, if L = 4, the first half refers to first 2 nodes. 

**Example :**

Given linked list `1 -> 2 -> 3 -> 4 -> 5`, 

You should return `4 -> 2 -> 3 -> 4 -> 5`
as 

```
for first node, 5 - 1 = 4
for second node, 4 - 2 = 2
```

Try to solve the problem using constant extra space. 

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
ListNode* reverseLinkedList(ListNode* node) {
    if (!node || !node->next) { return node; }
    ListNode* prevNode = 0; 
    ListNode* nextNode = node->next;
    ListNode* curNode = node;
    while(nextNode) {
        curNode->next = prevNode;
        
        prevNode = curNode;
        curNode = nextNode;
        nextNode = curNode->next;
    }
    curNode->next = prevNode;
    return curNode;
}

ListNode* Solution::subtract(ListNode* A) {
    if (!A || !A->next) { return A; }
    
    // Find mid and end of linkedList
    ListNode* mid = A;
    ListNode* end = A;
    while (end->next) {
        end = end->next;
        if (end->next) {
            end = end->next;
            mid = mid->next;
        }
    }
    // Reverse second half of the linked list
    mid->next = reverseLinkedList(mid->next);
    // Calculate the new values of first half of the linked list
    ListNode* startNode = A;
    ListNode* endNode = mid->next;
    while(endNode) {
        startNode->val = endNode->val - startNode->val;
        startNode = startNode->next;
        endNode = endNode->next;
    }
    
    // Reverse second half of linked list again
    mid->next = reverseLinkedList(mid->next);

    return A;
}
