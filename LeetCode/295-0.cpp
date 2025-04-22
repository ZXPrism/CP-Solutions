class MedianFinder {
public:
	std::priority_queue<int> ql;
	std::priority_queue<int, std::vector<int>, std::greater<>> qr;
	MedianFinder() {
		constexpr int INF = std::numeric_limits<int>::max();
		ql.push(-INF);
		qr.push(INF);
	}

	void addNum(int num) {
		auto left = ql.top(), right = qr.top();
		if (num <= left) {
			ql.push(num);
		} else {
			qr.push(num);
		}
		if (ql.size() > qr.size()) {
			qr.push(ql.top());
			ql.pop();
		} else if (qr.size() > ql.size() + 1) {
			ql.push(qr.top());
			qr.pop();
		}
	}

	double findMedian() {
		if (ql.size() == qr.size()) {
			return (ql.top() + qr.top()) / 2.0;
		} else {
			return qr.top();
		}
	}
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
