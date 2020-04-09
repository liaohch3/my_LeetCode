/*
* @Author: liaohch3
* @Date:   2020-04-05 17:28:02
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-04-05 18:38:43
*/

#include <iostream>
#include <stack>
#include <string>
#include <cstring>
#include <vector>
#include <list>
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

struct CacheNode
{
	int key, value, freq;
	list<int>::const_iterator it;
};

class LFUCache {
	//https://www.bilibili.com/video/BV1gt411Y7PR?from=search&seid=3486152489898930989

	// key -> CacheNode
	unordered_map<int, CacheNode> keyNodeMap;

	// freq -> list
	unordered_map<int, list<int> > freqListMap;
	int minFreq;
	int cap;

	void touch(CacheNode& node){
		// 从频次队列里删除相应的key节点
		freqListMap[node.freq].erase(node.it);

		// 如果删除的是最小的频次，且队列空
		if(node.freq == minFreq && freqListMap[node.freq].empty()){
			freqListMap.erase(minFreq);
			++minFreq;
		}

		// 将对应频次加一
		++(node.freq);

		// 插入到加一后的队列头
		freqListMap[node.freq].push_front(node.key);

		// 重新指向新的迭代器
		node.it = freqListMap[node.freq].cbegin();
	}

public:
    LFUCache(int capacity) :cap(capacity), minFreq(0){

    }
    
    int get(int key) {
    	auto it = keyNodeMap.find(key);
    	if(it == keyNodeMap.end()){
    		return -1;
    	}

    	touch(it->second);
    	return it->second.value;
    }
    
    void put(int key, int value) {
    	if(cap == 0)	return;
    	auto it = keyNodeMap.find(key);

    	if(it != keyNodeMap.end()){
    		it->second.value = value;
    		touch(it->second);
    		return;
    	}

    	if(keyNodeMap.size() == cap){
    		int popKey = freqListMap[minFreq].back();
    		keyNodeMap.erase(popKey);

    		freqListMap[minFreq].pop_back();
    		if(freqListMap[minFreq].empty()){
    			freqListMap.erase(minFreq);
    		}
    	}

    	minFreq = 1;
    	freqListMap[1].push_front(key);
    	CacheNode node{key, value, 1, freqListMap[1].cbegin()};
    	keyNodeMap[key] = node;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main()
{
    
	LFUCache cache = LFUCache( 2 /* capacity (缓存容量) */ );

	cache.put(1, 1);
	cache.put(2, 2);
	cout << cache.get(1) << endl;       // 返回 1
	cache.put(3, 3);    // 去除 key 2
	cout << cache.get(2) << endl;       // 返回 -1 (未找到key 2)
	cout << cache.get(3) << endl;       // 返回 3
	cache.put(4, 4);    // 去除 key 1
	cout << cache.get(1) << endl;       // 返回 -1 (未找到 key 1)
	cout << cache.get(3) << endl;       // 返回 3
	cout << cache.get(4) << endl;       // 返回 4

	// LFUCache cache = LFUCache( 2 /* capacity (缓存容量) */ );
	// cache.put(3, 1);
	// cache.put(2, 1);
	// cache.put(2, 2);
	// cache.put(4, 4);
	// cout << cache.get(2) << endl;       // 返回 1

    return 0;
}