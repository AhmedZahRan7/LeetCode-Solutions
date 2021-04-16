  class Solution {
    public ListNode partition(ListNode head, int x) {
        ListNode less = null, moreOrEqual= null,firstLess= null,firstME= null;
        while(head!=null){
            if(head.val < x){
                if(less==null){
                    less = head;
                    firstLess = head;
                }
                else {
                    less.next = head;
                    less=less.next;
                }
            }
            else{
                if(moreOrEqual==null) {
                    moreOrEqual = head;
                    firstME = head;
                }
                else {
                    moreOrEqual.next = head;
                    moreOrEqual=moreOrEqual.next;
                }
            }
            head = head.next;
        }
        if(less == null) return firstME;
        if(moreOrEqual==null) return firstLess;
        less.next = firstME;
        moreOrEqual.next = null;
        return firstLess;
    }
}