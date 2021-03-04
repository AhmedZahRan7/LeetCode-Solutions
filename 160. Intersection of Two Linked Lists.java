public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        Map<ListNode,Boolean> m = new HashMap<ListNode,Boolean>();
        while(headA != null) {
            m.put(headA, true);
            headA = headA.next;
        }
        while(headB != null) {
            if(m.containsKey(headB)) return headB;
            headB = headB.next;
        }
        return null;
    }
}