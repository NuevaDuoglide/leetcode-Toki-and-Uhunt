#include <unordered_map>

class LRUCache {
private:
    // Custom node untuk Doubly Linked List
    struct Node {
        int key;
        int val;
        Node* prev;
        Node* next;
        Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
    };

    int capacity;
    std::unordered_map<int, Node*> cache_map;
    
    // Dummy head dan tail untuk menghindari edge cases (node kosong)
    Node* head;
    Node* tail;

    // Fungsi helper untuk menghapus node dari linked list O(1)
    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    // Fungsi helper untuk menyisipkan node tepat setelah dummy head (sebagai Most Recently Used) O(1)
    void insertNode(Node* node) {
        node->next = head->next;
        node->next->prev = node;
        head->next = node;
        node->prev = head;
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        // Inisialisasi dummy nodes
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (cache_map.find(key) == cache_map.end()) {
            return -1; // Key tidak ditemukan
        }
        
        // Jika ditemukan, node ini menjadi yang paling sering digunakan (Most Recently Used)
        Node* node = cache_map[key];
        removeNode(node);
        insertNode(node); // Pindahkan ke depan (setelah head)
        
        return node->val;
    }
    
    void put(int key, int value) {
        if (cache_map.find(key) != cache_map.end()) {
            // Jika key sudah ada, update nilainya dan pindahkan ke depan
            Node* node = cache_map[key];
            node->val = value;
            removeNode(node);
            insertNode(node);
        } else {
            // Jika key belum ada dan kapasitas penuh
            if (cache_map.size() == capacity) {
                // Hapus node yang paling jarang digunakan (Least Recently Used), yaitu sebelum dummy tail
                Node* lru = tail->prev;
                cache_map.erase(lru->key);
                removeNode(lru);
                delete lru; // Bebaskan memori
            }
            
            // Masukkan node baru ke depan
            Node* newNode = new Node(key, value);
            cache_map[key] = newNode;
            insertNode(newNode);
        }
    }

    // Destructor untuk membersihkan memori heap
    ~LRUCache() {
        Node* curr = head;
        while (curr != nullptr) {
            Node* next = curr->next;
            delete curr;
            curr = next;
        }
    }
};