#include <bits/stdc++.h>
using namespace std;

class LRUCache {
public:
    LRUCache(int capacity) :
        ListSize(capacity),p(),s() {
    }

    int get(int key) {
        if (s.find(key) == s.end()) {
            return -1;
        }
        auto t = s[key];
        p.erase(t);
        p.emplace_front(make_pair(t->first,t->second));
        return s[key]->second;
    }

    void put(int key, int value) {
        if (s.find(key)!=s.end()){
           s[key]->second=value;
           p.splice(p.begin(),p,s[key]);
           return;
        }
        p.emplace_front(make_pair(key, value));
        s[key] = p.begin();
        if (p.size() > ListSize) {
            s.erase(p.back().first);
            p.pop_back();
        }
    }

private:
    int ListSize;
    list<pair<int, int>> p;
    map<int, list<pair<int, int>>::iterator> s;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
int main() {
    LRUCache *lRUCache = new LRUCache(2);
    int t;
    lRUCache->put(1, 1); // 缓存是 {1=1}
    lRUCache->put(2, 2); // 缓存是 {1=1, 2=2}
    t=lRUCache->get(1);    // 返回 1
    lRUCache->put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
    t=lRUCache->get(2);    // 返回 -1 (未找到)
    lRUCache->put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
    t=lRUCache->get(1);    // 返回 -1 (未找到)
    t=lRUCache->get(3);    // 返回 3
    t=lRUCache->get(4);    // 返回 4
    return 0;
}
