template<typename T>
class Fenwick {
private:
	size_t _N;
	std::vector<T> _Data;

public:
	explicit Fenwick(size_t n)
	    : _N(n) { _Data.resize(n + 1); }
	T Qry(int x) {
		T res{};
		while (x) {
			res += _Data[x];
			x &= x - 1;
		}
		return res;
	}
	void Add(int x, T val) {
		while (x <= _N) {
			_Data[x] += val;
			x += x & -x;
		}
	}
};

class Solution {
public:
	long long goodTriplets(vector<int> &nums1, vector<int> &nums2) {
		int n = nums1.size();
		std::vector<int> idx(n);
		for (int i = 0; i < n; i++) {
			idx[nums2[i]] = i;
		}
		std::vector<int> v(n);
		for (int i = 0; i < n; i++) {
			v[i] = idx[nums1[i]];
		}
		using i64 = long long;
		i64 ans = 0;
		Fenwick<int> f(n);
		for (int i = 0; i < n; i++) {
			int c1 = f.Qry(v[i]);
			int c2 = n - 1 - v[i] - (i - c1);
			ans += 1LL * c1 * c2;
			f.Add(v[i] + 1, 1);
		}
		return ans;
	}
};
