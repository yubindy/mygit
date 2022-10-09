#include <bits/stdc++.h>
using namespace std;

class LRUCache {
public:
    LRUCache(int capacity) {
        size=capacity;
    }
    
    int get(int key) {
        auto p=mp.find(key);
        if(p==mp.end()){
            return -1;
        }
        lt.splice(lt.begin(),lt,p->second);
        return p->second->second;
    }
    
    void put(int key, int value) {
        auto p=mp.find(key);
        if(p==mp.end()){
            lt.push_front(make_pair(key,value));
            mp[key]=lt.begin();
            if(size<lt.size()){
                mp.erase(lt.back().first);
                lt.pop_back();
            }
            return;
        }
       p->second->second=value;
       lt.splice(lt.begin(),lt,p->second);
    }
private:
    int size;
    list<pair<int,int>> lt;
    unordered_map<int,list<pair<int,int>>::iterator> mp;
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
