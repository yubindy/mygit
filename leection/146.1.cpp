#include "leection.h"
class LRUCache {
public:
    LRUCache(int capacity) {
        size = capacity;
    }

    int get(int key) {
        auto it = pmap.find(key);
        int val=-1;
        if (it != pmap.end()) {
            plist.splice(plist.begin(), plist, it->second);
            pmap[key] = plist.begin();
            val=plist.front().second;
        }
        return val;
    }

    void put(int key, int value) {
        auto it = pmap.find(key);
        if (it != pmap.end()) {
            plist.splice(plist.begin(), plist, it->second);
            plist.begin()->second=value;
            pmap[key] = plist.begin();
        } else {
            plist.push_front(pair<int, int>{key, value});
            pmap[key] = plist.begin();
            if (pmap.size() > size) {
                key = plist.back().first;
                pmap.erase(key);
                plist.pop_back();
            }
        }
        return;
    }

private:
    list<pair<int, int>> plist;
    map<int, list<pair<int, int>>::iterator> pmap;
    int size;
};
int main() {
    list<int> p;
}