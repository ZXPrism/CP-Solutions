class MovingAverage {
public:
    int sum = 0, len = 0;
    std::deque<int> data;

    MovingAverage(int size) {
        len = size;
    }

    double next(int val) {
        sum += val;
        data.push_back(val);
        double ans = 1.0 * sum / data.size();
        if (data.size() == len) {
            sum -= data.front();
            data.pop_front();
        }
        return ans;
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
