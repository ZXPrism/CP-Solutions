class BrowserHistory {
public:
    std::vector<std::string> history;
    int curr = 0, size = 1;

    BrowserHistory(string homepage) {
        history.push_back(homepage);
    }

    void visit(string url) {
        if (curr == history.size() - 1) {
            history.push_back(url);
            ++curr;
        } else {
            history[++curr] = url;
        }
        size = curr + 1;
    }

    string back(int steps) {
        curr = std::max(0, curr - steps);
        return history[curr];
    }

    string forward(int steps) {
        curr = std::min(size - 1, curr + steps);
        return history[curr];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
