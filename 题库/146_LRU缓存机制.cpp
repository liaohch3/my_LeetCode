/*
* @Author: liaohch3
* @Date:   2020-02-25 14:08:28
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-02-25 14:44:41
*/

#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <queue>
#include <list>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <limits.h>
#include <time.h>

using namespace std;

class LRUCache {

    int capacity;
    // key - val 双向链表
    list<pair<int, int> > cache;
    // 散列表 key => list迭代器
    unordered_map<int, list<pair<int, int> >::iterator> hashMap;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        // 如果找不到key 则返回-1
        if(hashMap.find(key) == hashMap.end())  return -1;

        // 存下副本
        pair<int, int> now = *hashMap[key];

        // 删除之
        cache.erase(hashMap[key]);

        // 在list头插入副本
        cache.push_front(now);

        // hash表指向它
        hashMap[key] = cache.begin();

        // 返回val
        return now.second;
    }
    
    void put(int key, int value) {
        if(hashMap.find(key) == hashMap.end()){
            if(cache.size() == capacity){
                pair<int, int> back = cache.back();
                cache.pop_back();
                hashMap.erase(back.first);
            }
        }else{
            cache.erase(hashMap[key]);
        }

        cache.push_front(make_pair(key, value));
        hashMap[key] = cache.begin();
    }
};

class LRUCache2 {
private:
    int cap;
    // 双链表：装着 (key, value) 元组
    list<pair<int, int> > cache;
    // 哈希表：key 映射到 (key, value) 在 cache 中的位置
    unordered_map<int, list<pair<int, int> >::iterator> map;
public:
    LRUCache2(int capacity) {
        this->cap = capacity; 
    }
    
    int get(int key) {
        auto it = map.find(key);
        // 访问的 key 不存在
        if (it == map.end()) return -1;
        // key 存在，把 (k, v) 换到队头
        pair<int, int> kv = *map[key];
        cache.erase(map[key]);
        cache.push_front(kv);
        // 更新 (key, value) 在 cache 中的位置
        map[key] = cache.begin();
        return kv.second; // value
    }
    
    void put(int key, int value) {

        /* 要先判断 key 是否已经存在 */ 
        auto it = map.find(key);
        if (it == map.end()) {
            /* key 不存在，判断 cache 是否已满 */ 
            if (cache.size() == cap) {
                // cache 已满，删除尾部的键值对腾位置
                // cache 和 map 中的数据都要删除
                auto lastPair = cache.back();
                int lastKey = lastPair.first;
                map.erase(lastKey);
                cache.pop_back();
            }
            // cache 没满，可以直接添加
            cache.push_front(make_pair(key, value));
            map[key] = cache.begin();
        } else {
            /* key 存在，更改 value 并换到队头 */
            cache.erase(map[key]);
            cache.push_front(make_pair(key, value));
            map[key] = cache.begin();
        }
    }
};

int main()
{

    // Your LRUCache object will be instantiated and called as such:
    LRUCache* obj = new LRUCache(2);
    obj->put(1, -1);
    int param_1 = obj->get(1);
    obj->put(2, -2);
    
    return 0;
}