class Node {
    int value;
    int key;
    Node prev, next;

    public Node(int key, int value) {
        this.value=value;
        this.key=key;
    }

}

class LRUCache {

    private final int capacity;
    private Map<Integer, Node> map;
    private final Node head;
    private final Node tail;

    public LRUCache(int capacity) {
        this.capacity=capacity;
        map = new HashMap<>();
        head=new Node(0,0);
        tail=new Node(0,0);
        head.next=tail;
        tail.prev=head;
        
    }
    
    public int get(int key) {
        Node node = map.get(key);
        if (node==null) {
            return -1;
        }

        remove(node);
        addToHead(node);
        
        return node.value;
    }
    
    public void put(int key, int value) {
        if (capacity==0) {
            return;
        }

        Node node = map.get(key);

        if (node!=null) {
            node.value=value;
            remove(node);
            addToHead(node);
            return;
        }

        if (map.size()==capacity) {
            Node lru = tail.prev;
            remove(lru);
            map.remove(lru.key);
        }

        Node newNode = new Node(key, value);
        map.put(key, newNode);
        addToHead(newNode);
        
    }

    public void remove(Node node) {
        Node after = node.next;
        Node before = node.prev;
        before.next=after;
        after.prev=before;
    }

    public void addToHead(Node node) {
        Node first = head.next;

        node.next=first;
        node.prev=head;

        head.next=node;
        first.prev=node;
    }
}
