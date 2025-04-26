class Solution {
public:
	string decodeString(string s) {
		std::stack<std::string> st;
		std::stack<int> st_num;
		st.push("");

		int i = 0, n = s.size();
		while (i < n) {
			if (s[i] >= 'a' && s[i] <= 'z') {
				st.top().push_back(s[i]);
			} else if (s[i] >= '0' && s[i] <= '9') {
				int num = 0;
				while (s[i] != '[') {
					num = num * 10 + (s[i] - '0');
					++i;
				}
				st_num.push(num);
				st.push("");
			} else {
				int repeat_time = st_num.top();
				st_num.pop();
				auto repeat_s = st.top();
				st.pop();
				while (repeat_time--) {
					st.top() += repeat_s;
				}
			}
			++i;
		}

		return st.top();
	}
};
