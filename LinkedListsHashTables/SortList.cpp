/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* mergeLists(ListNode* A, ListNode* B) {
    if (!A) { return B; }
    if (!B) { return A; }
    
    ListNode* start = NULL;
    ListNode* cur = NULL;
    ListNode* next1 = A;
    ListNode* next2 = B;
    
    //cout<<"Merge: starting from "<<A->val<<" and "<<B->val<<endl;
    while (next1 || next2) {
        if (next1 && next2) {
            //cout<<"Merge: comparing "<<next1->val<<" and "<<next2->val<<endl;
            if (next1->val <= next2->val) {
                if(!cur) {
                    start = next1;
                    cur = next1;
                }
                else {
                    cur->next = next1;
                    cur = cur->next;
                }
                next1 = next1->next;
            }
            else {
                if(!cur) {
                    start = next2;
                    cur = next2;
                }
                else {
                    cur->next = next2;
                    cur = cur->next;
                }
                next2 = next2->next;
            }
        }
        else if (next1) {
            //cout<<"Merging next1 = "<<next1->val<<endl;
            cur->next = next1;
            next1 = next1->next;
            cur = cur->next;
        }    
        else if (next2) {
            //cout<<"Merging next2 = "<<next2->val<<endl;
            cur->next = next2;
            next2 = next2->next;
            cur = cur->next;
        }
    }
    return start;
}

ListNode* Solution::sortList(ListNode* A) {
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
    
    //cout<<"Mid = "<<mid->next->val<<endl;
    ListNode* secondListStart = mid->next;
    mid->next = NULL;
    ListNode* list1 = sortList(A);
    ListNode* list2 = sortList(secondListStart);
    
    return mergeLists(list1, list2);
}
