class Solution {

    ListNode reverseList(ListNode head){
        if (head == null || head.next == null) return head;
        ListNode prev = null;
        ListNode next = null;
        while (head!=null){
            next = head.next;
            head.next = prev;
            prev = head;
            head = next;
        } 
        return prev;
    }
    public boolean isPalindrome(ListNode head) {
        int n=0;
        ListNode pointer = head;
        while(pointer!=null){
            n++;
            pointer=pointer.next;
        }

        ListNode halfList = head;
        int t = 0;
        while(t < (n+1)/2) {
            halfList = halfList.next;
            t++;
        }
        halfList = reverseList(halfList);
        while(halfList!=null){
            if(halfList.val != head.val) return false;
            halfList = halfList.next;
            head = head.next;
        }
        return true;

    }
}