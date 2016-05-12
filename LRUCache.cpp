class Node {
public:
	int key;
	int value;
	Node *next, *prev;
	Node(int key, int value): key(key), value(value), next(NULL), prev(NULL) {}
};

class DoubleLinkList{
private:
	Node *head, *tail;
	int size;

public:
	DoubleLinkList() {
		head = tail = NULL;
		size = 0;
	}

	~DoubleLinkList() {
		while (head) {
			Node *tmp = head;
			head = head->next;
			delete tmp;
		}
	}

	int Size() {
		return size;
	}

	Node* PushFront(Node *elem) {
		++size;

		if (head == NULL) {
			head = tail = elem;
			return elem;
		}

		elem->next = head;
		elem->prev = NULL;
		head->prev = elem;
		head = elem;
		return elem;
	}

	void UnlinkNode(Node *elem) {
		Node *prev = elem->prev;
		Node *next = elem->next;
		if (prev)
			prev->next = elem->next;

		if (next)
			next->prev = elem->prev;

		if (head == elem)
			head = head->next;

		if (tail == elem)
			tail = tail->prev;

		--size;
	}

	void DeleteNode(Node *elem) {
		UnlinkNode(elem);
		delete elem;
	}

	void DeleteLastNode() {
		DeleteNode(tail);
	}

	Node* GetLastNode() {
		return tail;
	}

	void MoveToFront(Node *elem) {
		UnlinkNode(elem);
		PushFront(elem);
	}

	void Print() {
		Node *tmp = head;
		while (tmp) {
			cout << "(" << tmp->key << " " << tmp->value << ") ";
			tmp = tmp->next;
		}
	}
};

class LRUCache{
public:
	LRUCache(int capacity) {
		this->capacity = capacity;
	}

	int get(int key) {
		if (cacheMap.find(key) != cacheMap.end()) {
			cacheList.MoveToFront(cacheMap[key]);
			return cacheMap[key]->value;
		}
		return -1;
	}

	void set(int key, int value) {
		if (cacheMap.find(key) != cacheMap.end()) {
			cacheList.MoveToFront(cacheMap[key]);
			cacheMap[key]->value = value;
		} else {
			Node *elem = new Node(key, value);
			cacheList.PushFront(elem);
			cacheMap[key] = elem;
			if (cacheList.Size() > capacity) {
				int lastKey = cacheList.GetLastNode()->key;
				cacheMap.erase(lastKey);
				cacheList.DeleteLastNode();
			}
		}
	}

private:
	DoubleLinkList cacheList;
	int capacity;
	map<int, Node*> cacheMap;
};