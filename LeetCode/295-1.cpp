class MedianFinder {
public:
	std::priority_queue<int> ql;
	std::priority_queue<int, std::vector<int>, std::greater<>> qr;
	MedianFinder() {}

	void addNum(int num) {
		if (ql.size() == qr.size()) {
			ql.push(num);
			qr.push(ql.top());
			ql.pop();
		} else {
			qr.push(num);
			ql.push(qr.top());
			qr.pop();
		}
	}

	double findMedian() {
		if (ql.size() == qr.size()) {
			return (ql.top() + qr.top()) / 2.0;
		}
		return qr.top();
	}
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
