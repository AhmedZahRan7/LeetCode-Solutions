class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return NULL;
        int n=1;
        ListNode* p = head;
        while(p->next){
            p=p->next;
            n++;
        }
        k %=n; 
        p->next=head;
        p = head;
        for(int i=1;i<n-k;i++) p=p->next;
        ListNode* newh = p->next;
        p->next = NULL;
        return newh;
    }
};