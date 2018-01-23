/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseBetween(ListNode* A, int B, int C) {
    if (B==C) {return A;}
    
    ListNode* startNode = A;
    int curPosition = 1;
    while(curPosition < B-1) {
        startNode = startNode->next;
        curPosition++;
    }
    
    ListNode* currentNode;
    if (B==1) {
        currentNode = startNode;
        curPosition = 0;
    }
    else {
        currentNode = startNode->next;
    }
    
    ListNode* reversedListEndNode = currentNode;
    ListNode* prevNode = NULL;
    
    while (curPosition < C) {
        ListNode* temp;
        temp = currentNode->next;
        currentNode->next = prevNode;
        prevNode = currentNode;
        currentNode = temp;
        curPosition++;
    }

    if (B == 1) {
        reversedListEndNode->next = currentNode;
        return prevNode;
    } 
    else {
        startNode->next = prevNode;
        reversedListEndNode->next = currentNode;
    }
    return A;
    
}
