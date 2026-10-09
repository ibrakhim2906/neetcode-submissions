class ListNode {
    int value;
    ListNode next;
    ListNode prev;
    
    public ListNode(int value, ListNode next, ListNode prev) {
        this.prev = prev;
        this.value = value;
        this.next = next;
    }

    public ListNode(int value) {
        this(value, null, null);
    }
}

class Deque {
    private ListNode head;
    private ListNode tail;

    public Deque() {
        head = new ListNode(0);
        tail = head;

    }

    public boolean isEmpty() {
        return head==tail;
    }

    public void append(int value) {
        ListNode node = new ListNode(value);
        if (this.isEmpty()) {
            head.next=node;
            node.prev=head;
            tail=node;
            return;
        }
       
        tail.next=node;
        node.prev=tail;
        tail=node;
    }

    public void appendleft(int value) {
        ListNode node = new ListNode(value);
        if (this.isEmpty()) {
            head.next=node;
            node.prev=head;
            tail=node;
            return;
        }

        node.next=head.next;
        head.next.prev=node;
        node.prev=head;
        head.next=node;
    }

    public int pop() {
        if (this.isEmpty()) {
            return -1;
        }

        ListNode toReturn = tail;

        ListNode temp = tail.prev;
        tail.prev.next=null;
        tail.prev=null;
        tail=temp;

        return toReturn.value;
    }

    public int popleft() {
        if (this.isEmpty()) {
            return -1;
        }

        ListNode toReturn = head.next;
        head.next=toReturn.next;

        if (head.next!=null) head.next.prev=head;
        else tail=head;

        toReturn.next=null;
        toReturn.prev=null;

        return toReturn.value;
    }
}
