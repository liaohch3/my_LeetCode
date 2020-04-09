/*
* @Author: liaohch3
* @Date:   2020-04-05 12:44:26
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-04-05 16:30:36
*/

#include <iostream>
#include <stack>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <limits.h>
#include <time.h>

using namespace std;

struct CacheNode{
	int key;	// 键
	int value;	// 值
	int freq;	// 频次
	int tick;	// 时间

	bool operator<(const CacheNode& c)const {
		return freq == c.freq ? tick < c.tick : freq < c.freq;
	}
};

class LFUCache {
	set<CacheNode> cache;
	unordered_map<int, CacheNode> hashMap;
	int cap;
	static int statick;

	void touch(CacheNode& node){
		cache.erase(node);
		node.tick = ++LFUCache::statick;
		++node.freq;
		cache.insert(node);
	}

public:
    LFUCache(int capacity) {
    	cap = capacity;
    }
    
    int get(int key) {
    	// 哈希表查找key，找不到则返回-1
    	auto it = hashMap.find(key);
    	if(it == hashMap.end())
    		return -1;

    	// 找到相应的迭代器
    	int res = it->second.value;

    	// 触摸一下，更新他的时间
    	touch(it->second);

    	// 返回value
    	return res;
    }
    
    void put(int key, int value) {
    	if(cap == 0)	return;

    	auto it = hashMap.find(key);

    	// 哈希表查找key，找到则更新
    	if(it != hashMap.end()){
    		it->second.value = value;
    		touch(it->second);
    		return;
    	}

    	if(hashMap.size() == cap){
    		const CacheNode& node = *cache.cbegin();
    		hashMap.erase(node.key);
    		cache.erase(node);
    	}

    	CacheNode node{key, value, 1, ++LFUCache::statick};
    	hashMap[key] = node;
    	cache.insert(node);
    }
};

int LFUCache::statick = 0;

int main()
{
	// LFUCache cache = LFUCache( 2 /* capacity (缓存容量) */ );

	// cache.put(1, 1);
	// cache.put(2, 2);
	// cout << cache.get(1) << endl;       // 返回 1
	// cache.put(3, 3);    // 去除 key 2
	// cout << cache.get(2) << endl;       // 返回 -1 (未找到key 2)
	// cout << cache.get(3) << endl;       // 返回 3
	// cache.put(4, 4);    // 去除 key 1
	// cout << cache.get(1) << endl;       // 返回 -1 (未找到 key 1)
	// cout << cache.get(3) << endl;       // 返回 3
	// cout << cache.get(4) << endl;       // 返回 4

	LFUCache cache = LFUCache( 2 /* capacity (缓存容量) */ );
	cache.put(3, 1);
	cache.put(2, 1);
	cache.put(2, 2);
	cache.put(4, 4);
	cout << cache.get(2) << endl;       // 返回 1

    return 0;
}