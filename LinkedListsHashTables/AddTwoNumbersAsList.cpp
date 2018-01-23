/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
    ListNode* result = NULL;
    ListNode* prev = NULL;
    bool carry = false;
    while(A||B||carry) {
        // Calculate value
        int value = carry? 1: 0;
        carry = false;
        if(A) {
            value += A->val;
            A = A->next;
        }
        if (B) {
            value += B->val;
            B = B->next;
        }
        if(value>9) {
            carry = true;
            value = value%10;
        }
        
        //cout<<"New node with value "<<value<<endl;
        ListNode* current = new ListNode(value);
        if (prev == NULL) {
            result = current;
        }
        else {
            prev->next = current;
        }
        prev = current;
    }
    
    return result;
}
