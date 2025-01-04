#include <bits/stdc++.h>
using namespace std;

struct Sqrt {
	int block_size;
	vector<int> nums;
	vector<long long> blocks;
	Sqrt(int sqrtn, vector<int> &arr) : block_size(sqrtn), blocks(sqrtn, 0) {
		nums = arr;
		for (int i = 0; i < nums.size(); i++) { blocks[i / block_size] += nums[i]; }
	}

	/** O(1) update to set nums[x] to v */
	void update(int x, int v) {
		blocks[x / block_size] -= nums[x];
		nums[x] = v;
		blocks[x / block_size] += nums[x];
	}

	/** O(sqrt(n)) query for sum of [0, r) */
	long long query(int r) {
		long long res = 0;
		for (int i = 0; i < r / block_size; i++) { res += blocks[i]; }
		for (int i = (r / block_size) * block_size; i < r; i++) { res += nums[i]; }
		return res;
	}

	/** O(sqrt(n)) query for sum of [l, r) */
	long long query(int l, int r) { return query(r) - query(l - 1); }
};

int main() {
	int n, q;
	cin >> n >> q;

	vector<int> arr(n);
	for (int i = 0; i < n; i++) { cin >> arr[i]; }
	Sqrt sq((int)ceil(sqrt(n)), arr);

	for (int i = 0; i < q; i++) {
		int t, l, r;
		cin >> t >> l >> r;
		if (t == 1) {
			sq.update(l - 1, r);
		} else {
			cout << sq.query(l, r) << "\n";
		}
	}
}