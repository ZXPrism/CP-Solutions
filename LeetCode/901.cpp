class StockSpanner {
public:
    std::stack<int> st;
    std::vector<int> prices;

    StockSpanner() {
        st.push(-1);
    }

    int next(int price) {
        while (st.size() != 1 && price >= prices[st.top()]) {
            st.pop();
        }
        int ans = prices.size() - st.top();
        st.push(prices.size());
        prices.push_back(price);
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
