class ListNode {
    int value;
    ListNode next;

    public ListNode(int value) {
        this(value, null);
    }

    public ListNode(int value, ListNode next) {
        this.value = value;
        this.next = next;
    }
}

class LinkedList {
    private ListNode head;
    private ListNode tail;

    public LinkedList() {
        head = new ListNode(0);
        tail = head;
    }

    public int get(int index) {
        ListNode curr = head.next;
        while (curr!=null && index!=0) {
            curr=curr.next;
            index--;
        }
        if (curr==null) {
            return -1;
        }
        return curr.value;
    }

    public void insertHead(int val) {
        ListNode node = new ListNode(val);
        node.next=head.next;
        head.next=node;
        if (head==tail) tail=node;
    }

    public void insertTail(int val) {
        this.tail.next=new ListNode(val);
        this.tail = this.tail.next;
    }

    public boolean remove(int index) {
        ListNode toRemove = head.next;
        ListNode beforeRemove = head;
        while (toRemove!=null && index!=0) {
            ListNode temp = toRemove;
            toRemove = toRemove.next;
            beforeRemove = temp;
            index--;
        } 
        if (toRemove==null) {
            return false;
        }
        beforeRemove.next=toRemove.next;

        if (toRemove == tail) {
            tail = beforeRemove;
        }

        return true;
    }

    public ArrayList<Integer> getValues() {
        ArrayList<Integer> values = new ArrayList<>();
        if (head.next==null) {
            return values;
        } 
        ListNode curr = head.next;
        while (curr!=null) {
            values.add(curr.value);
            curr=curr.next;
        }
        return values;
    }
}
