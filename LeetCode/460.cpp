struct DCLinkedListNode {
	int _Key, _Value, _Freq;
	DCLinkedListNode *_Next, *_Prev;
};

class DCLinkedList {
private:
	DCLinkedListNode _Dummy;
	int _NodeCnt;

public:
	DCLinkedList()
	    : _NodeCnt(0) {
		_Dummy._Next = &_Dummy;
		_Dummy._Prev = &_Dummy;
	}

	void insert_before_head(DCLinkedListNode *node) {
		insert_after(&_Dummy, node);
	}

	void insert_after(DCLinkedListNode *base, DCLinkedListNode *node) {
		auto next = base->_Next;
		base->_Next = node;
		next->_Prev = node;
		node->_Prev = base;
		node->_Next = next;
		++_NodeCnt;
	}

	DCLinkedListNode *remove(DCLinkedListNode *node) {
		auto prev = node->_Prev;
		auto next = node->_Next;
		prev->_Next = next;
		next->_Prev = prev;
		--_NodeCnt;
		return node;
	}

	DCLinkedListNode *remove_tail() { return remove(_Dummy._Prev); }

	int get_node_cnt() const { return _NodeCnt; }
};

class LFUCache {
private:
	int _Cap, _MinFreq, _Cnt;
	std::unordered_map<int, DCLinkedList> _Freq2List;
	std::unordered_map<int, DCLinkedListNode *> _Key2Node;

public:
	LFUCache(int capacity)
	    : _Cap(capacity)
	    , _MinFreq(1)
	    , _Cnt(0) {}

	int get(int key) {
		auto iter = _Key2Node.find(key);
		if (iter != _Key2Node.end()) {
			auto node = iter->second;
			_use(node);
			return node->_Value;
		}
		return -1;
	}

	void put(int key, int value) {
		auto iter = _Key2Node.find(key);
		if (iter != _Key2Node.end()) {
			auto node = iter->second;
			node->_Value = value;
			_use(node);
		} else {
			if (_Cnt == _Cap) {
				auto rm_node = _Freq2List[_MinFreq].remove_tail();
				_Key2Node.erase(rm_node->_Key);
				delete rm_node;
				--_Cnt;
			}

			auto new_node = new DCLinkedListNode();
			new_node->_Key = key;
			new_node->_Value = value;
			new_node->_Freq = 1;

			_Key2Node[key] = new_node;
			_Freq2List[1].insert_before_head(new_node);
			++_Cnt;

			_MinFreq = 1;
		}
	}

private:
	void _use(DCLinkedListNode *node) {
		int freq = node->_Freq;
		DCLinkedList &list = _Freq2List[freq];
		DCLinkedList &next_list = _Freq2List[freq + 1];

		++node->_Freq;
		list.remove(node);
		next_list.insert_before_head(node);

		if (list.get_node_cnt() == 0 && freq == _MinFreq) {
			++_MinFreq;
		}
	}
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
