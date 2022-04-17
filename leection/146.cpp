#include<list>
#include<unordered_map>
class lrunode{
public:
    lrunode(int cap):n(cap){}
   std::list<int> t;
   std::unordered_map<int,int> s;
   int n;
};
class LRUCache {
public:
    LRUCache(int capacity) {
        lrunode(capacity);

    }
    
    int get(int key) {

    }
    
    void put(int key, int value) {

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */