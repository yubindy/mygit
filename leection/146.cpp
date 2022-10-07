#include <bits/stdc++.h>
using namespace std;

class LRUCache {
public:
    LRUCache(int capacity):cpa(capacity),size(0),llist(),lmap() {
    }

    int get(int key) {
        if (lmap.find(key) == lmap.end()) {
            return -1;
        }
        int n=lmap[key]->second;
        llist.erase(lmap[key]);
        llist.emplace_front(make_pair(key,n));
        lmap[key] = llist.begin();
        return lmap[key]->second;
    }

    void put(int key, int value) {
        if (lmap.find(key) != lmap.end()) {
            llist.erase(lmap[key]);
            llist.emplace_front(make_pair(key, value));
            lmap[key] = llist.begin();
        } else {
            llist.emplace_front(make_pair(key, value));
            lmap[key] = llist.begin();
            size++;
            if (size > cpa) {
                lmap.erase(llist.back().first);
                llist.pop_back();
                size--;
            }
        }
    }

private:
    int cpa;
    int size;
    list<pair<int, int>> llist;
    map<int, list<pair<int, int>>::iterator> lmap;
};


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

void fix(int n, int t) {
    if (n != t) {
        printf("get error %d:", t);
        //exit(0);
    }
}
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
int main() {
    LRUCache *lRUCache = new LRUCache(2);
    int t;
    lRUCache->put(1, 1);  // 缓存是 {1=1}
    lRUCache->put(2, 2);  // 缓存是 {1=1, 2=2}
    t = lRUCache->get(1); // 返回 1
    fix(1, t);
    lRUCache->put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}

    t = lRUCache->get(2); // 返回 -1 (未找到)
    fix(t, -1);
    lRUCache->put(4, 4);  // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
    t = lRUCache->get(1); // 返回 -1 (未找到)
    fix(t, -1);
    t = lRUCache->get(3); // 返回 3
    fix(t, 3);

    t = lRUCache->get(4); // 返回 4
    fix(t, 4);
    delete(lRUCache);
    return 0;
}
