#include <iostream>
#include <map>
#include <stack>
#include <list>
using namespace std;

class LRUCache{
private:
	map<int, list<pair<int, int>>::iterator > cap;
	list<pair<int, int>> useStack;
	int capacity;

public:

	LRUCache(int capacity) {
		this->capacity = capacity;
	}

	int get(int key) {
		if (cap.find(key) == cap.end())
		{
			return -1;
		}
		else
		{
			pair<int, int> tmp(*cap[key]);
			useStack.push_front(tmp);

			useStack.erase(cap[key]);
			cap[key] = useStack.begin();
			return cap[key]->second;
		}
	}

	void set(int key, int value) {
		if (cap.find(key) != cap.end())
		{
			pair<int, int> tmp(cap[key]->first, value);
			useStack.push_front(tmp);

			useStack.erase(cap[key]);
			cap[key] = useStack.begin();
			return;
		}
		if (cap.size()<capacity)
		{
			useStack.push_front(pair<int, int>(key, value));
			cap[key] = useStack.begin();
		}
		else
		{
			cap.erase(cap.find(useStack.back().first));
			useStack.pop_back();
			useStack.push_front(pair<int, int>(key, value));
			cap[key] = useStack.begin();
		}
	}
};

int main()
{
	LRUCache lruCache(2);
	lruCache.set(2, 1);
	lruCache.set(1, 1);
	lruCache.set(2, 3);
	lruCache.set(4, 1);
	cout << lruCache.get(1) << endl;
	cout << lruCache.get(2) << endl;
	cout << lruCache.get(4) << endl;
	lruCache.set(4, 37);
	lruCache.set(2, 47);
	cout << lruCache.get(2) << endl;
	cout << lruCache.get(4) << endl;
	lruCache.set(5, 97);
	lruCache.set(8, 87);
	cout << lruCache.get(1) << endl;
	cout << lruCache.get(5) << endl;

}