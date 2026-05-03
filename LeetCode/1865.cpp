class FindSumPairs {
public:
	std::vector<int> v1, v2;
	std::unordered_map<int, int> hashmap;

	FindSumPairs(vector<int> &nums1, vector<int> &nums2) {
		v1.swap(nums1);
		v2.swap(nums2);
		for (auto elem : v2) {
			++hashmap[elem];
		}
	}

	void add(int index, int val) {
		--hashmap[v2[index]];
		v2[index] += val;
		++hashmap[v2[index]];
	}

	int count(int tot) {
		int res = 0;
		for (auto elem : v1) {
			res += hashmap[tot - elem];
		}
		return res;
	}
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
