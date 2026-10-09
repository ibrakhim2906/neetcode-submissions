class LRUCache {

    private HashMap<Integer, Integer> cache;
    private LinkedList<Integer> recentKeys;
    private int capacity;

    public LRUCache(int capacity) {
        cache = new HashMap<>();
        this.capacity=capacity;
        recentKeys = new LinkedList<>();
        
    }
    
    public int get(int key) {
        if (!cache.containsKey(key)) {
            return -1;
        }

        recentKeys.remove((Integer) key);
        recentKeys.addLast(key);
        return cache.get(key);
        
    }
    
    public void put(int key, int value) {
    
        if (cache.containsKey(key)) {
            recentKeys.remove((Integer) key);
        } else if (cache.size()==capacity) {
            int lru = recentKeys.removeFirst();
            cache.remove(lru);
        }

        cache.put(key, value);
        recentKeys.addLast(key);
    }
}
