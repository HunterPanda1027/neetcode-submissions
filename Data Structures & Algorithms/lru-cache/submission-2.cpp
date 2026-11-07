class LRUCache {
private:
    int capacity;
    unordered_map<int, int> hashMap;
    list<int> doublyLinkedList;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (hashMap.contains(key)) {
            auto it = find(doublyLinkedList.begin(), doublyLinkedList.end(), key);
            doublyLinkedList.splice(doublyLinkedList.end(), doublyLinkedList, it);
            return hashMap[key];

        }
        return -1;
    }
    
    void put(int key, int value) {
        if (hashMap.contains(key)) {
            hashMap[key] = value;
            auto it = find(doublyLinkedList.begin(), doublyLinkedList.end(), key);
            doublyLinkedList.splice(doublyLinkedList.end(), doublyLinkedList, it);
        } else {
            if (hashMap.size() == capacity) {
                hashMap.erase(doublyLinkedList.front());
                doublyLinkedList.pop_front();
            }
            hashMap[key] = value;
            doublyLinkedList.push_back(key);
        }
        
    }
};
