/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* reverseList(ListNode* A) {
    ListNode * prev = NULL;
    ListNode * cur = A;
    ListNode * next = cur->next;
    
    while(cur) {
        //cout<<cur->val<<endl;
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}

void mergeLists(ListNode* A, ListNode* B) {
    if (!A) { return; }
    if (!B) { return; }
    
    ListNode* cur = A;
    ListNode* next1 = B;
    ListNode* next2 = A->next;
    
    while (next1 || next2) {
        if (next1) {
            cur->next = next1;
            next1 = next1->next;
            cur = cur->next;
        }    
        if (next2) {
            cur->next = next2;
            next2 = next2->next;
            cur = cur->next;
        }
    }
}

void printList(ListNode* A) {
    while (A) {
        cout<<A->val<<"->";
        A = A->next;
    }
    cout<<endl;
}

ListNode* Solution::reorderList(ListNode* A) {
    if (!A) { return NULL; }
    if (!(A->next)) { return A; }
    // Find middle of List
    ListNode* mid = A;
    ListNode* end = A;

    while (end) {
        end = end->next;
        if (end&&end->next) {
            end = end->next;
            mid = mid->next;
        }    
    }
    
    // Reverse half of the list
    //cout<<"Reverse "<<mid->next->val<<endl;
    ListNode* secondList = reverseList(mid->next);
    mid->next = NULL;
    /*cout<<"First List after reversal"<<endl;
    printList(A);
    cout<<"Second List after reversal"<<endl;
    printList(secondList);
    // Merge the two lists
    cout<<"Merge"<<endl;
    */
    mergeLists(A, secondList);
    
    return A;
}
