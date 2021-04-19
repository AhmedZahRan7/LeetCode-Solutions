class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* pointer = head;
        ListNode* ans = NULL;
        while(pointer!=NULL){
            if(n==0) ans = head;
            else if(n<0) ans = ans->next;
            n--;
            pointer = pointer->next;
        }
        if(ans == NULL) head = head->next;
        else if(ans->next!=NULL) ans->next = ans->next->next;
        return head;
    }
};