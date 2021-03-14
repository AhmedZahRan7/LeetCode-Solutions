class Solution {
    public ListNode swapNodes(ListNode head, int k) {
        int counter = 0;
        int reverseCounter = k;
        ListNode node1 = head;
        ListNode node2 = head;
        ListNode iter = head;
        while(iter!=null){
            counter++;
            reverseCounter--;
            if(counter==k) node1=iter;
            if(reverseCounter<0) node2=node2.next;
            iter=iter.next;
        }
        
        int temp = node1.val;
        node1.val=node2.val;
        node2.val=temp;

        return head;
    }
}