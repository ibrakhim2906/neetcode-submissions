class ListNode
{
    public:
        int key;
        int val;
        ListNode* next;
        ListNode* prev;

        ListNode(int key, int val): key{key}, val{val}, next{nullptr}, prev{nullptr} 
        {

        }
};

class LRUCache {
private:
    int capacity;
    unordered_map<int, ListNode*> cache{};
    ListNode* left;
    ListNode* right;

    void insert(ListNode* node)
    {
        ListNode* prev = right->prev;
        prev->next = node;
        node->prev = prev;
        node->next = right;
        right->prev = node;
    }

    void remove(ListNode* node)
    {
        ListNode* next = node->next;
        ListNode* prev = node->prev;
        next->prev = prev;
        prev->next = next;
    }
    
public:
    LRUCache(int capacity): capacity{capacity} {
        
        left = new ListNode(0,0);
        right = new ListNode(0,0);
        left->next = right;
        right->prev = left;
        
    }
    
    int get(int key) {
        if (cache.contains(key))
        {
            ListNode* node = cache[key];
            remove(node);
            insert(node);
            return node->val;
        }
        return -1;
        
    }
    
    void put(int key, int value) {
        if (cache.contains(key))
        {
            remove(cache[key]);
        }

        ListNode* newNode = new ListNode(key, value);
        cache[key] = newNode;
        insert(newNode);

        if (cache.size()>capacity)
        {
            ListNode* to_remove = left->next;
            remove(to_remove);
            cache.erase(to_remove->key);
            delete to_remove;
        }
        
    }
};
