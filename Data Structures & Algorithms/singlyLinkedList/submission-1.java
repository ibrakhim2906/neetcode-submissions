class ListNode {
    int val;
    ListNode next;

    public ListNode(int val) {
        this.val = val;
    }

    public ListNode() {
        this(0);
    }
}
class LinkedList {

    ListNode dummy;
    ListNode tail;

    public LinkedList() {
        dummy = new ListNode();
        tail = dummy;
    }

    public int get(int index) {
        
        int n = index;
        ListNode curr = dummy.next;

        while (n!=0 && curr!=null) {
            curr = curr.next;
            n--;
        }

        return (curr==null) ? -1 : curr.val;
    }

    public void insertHead(int val) {

        ListNode head = dummy.next;

        ListNode newNode = new ListNode(val);

        newNode.next = head;

        dummy.next = newNode;

        if (newNode.next==null) {
            tail = newNode;
        }
        
    }

    public void insertTail(int val) {

        ListNode newNode = new ListNode(val);

        tail.next = newNode;

        tail = newNode;

    }

    public boolean remove(int index) {

        int i = 0;
        ListNode prev = dummy;
        ListNode curr = dummy.next;

        while (i<index && curr!=null) {
            prev = curr;
            curr = curr.next;
            i++;
        }

        if (curr == null) {
            return false;
        }

        if (curr.next==null) {
            tail = prev;

        }

        prev.next = curr.next;

        return true;
    }

    public ArrayList<Integer> getValues() {

        ArrayList<Integer> values = new ArrayList<>();

        ListNode curr = dummy.next;

        while (curr!=null) {
            values.add(curr.val);
            curr = curr.next;
        }

        return values;

    }
}
