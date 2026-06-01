struct Node{
    int key, val;
    Node* prev;
    Node* next;

    Node(int k, int v): key(k), val(v), prev(nullptr), next(nullptr) {};
};
class LRUCache {
private:
    int cap;
    unordered_map<int, Node*> cache;
    Node* left;
    Node* right;
    void remove(Node* node){
        Node* prev_node = node->prev;
        Node* next_node = node->next;
        prev_node->next = next_node;
        next_node->prev = prev_node;
    }
    void insert(Node* node){
        Node* prev_node = right->prev;
        prev_node->next = node; 
        node->prev = prev_node;
        node->next = right;
        right->prev = node;
    }
public:
    LRUCache(int capacity) {
        cap = capacity;
        cache.clear();
        left = new Node(0,0);
        right = new Node(0,0); 
        left->next = right;
        right->prev = left;

    }
    
    int get(int key) {
        if(cache.find(key) != cache.end()){
            Node* node = cache[key];
            remove(node);
            insert(node);
            return node->val;
        }
        else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(cache.find(key) != cache.end()){
            remove(cache[key]);
        }
        Node *newNode = new Node(key, value);
        cache[key] = newNode;
        insert(newNode);

        if(cache.size() > cap){
            Node* lru = left->next;
            remove(lru);
            cache.erase(lru->key);
            delete lru;
        }
    }
};
