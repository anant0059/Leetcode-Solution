class Solution {
public:
	int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
		// For abbrevity
		auto& s = arr1;
		auto& t = arr2;
		
		if (s.empty()) return 0;
		
		// sort t and make elements unique
		sort(t.begin(), t.end());
		t.resize(unique(t.begin(), t.end()) - t.begin());

		int m = arr1.size();
		int n = arr2.size();
		
		// Number of minimum replacement required in s[0..i] if we replace s[i] with t[j]
		vector<vector<int>> f(m, vector<int>(n, INT_MAX));
		// Number of minimum replacement required in s[0..i] if we don't replace s[i]
		vector<int> g(m, INT_MAX);

		for (int i = 0; i < n; i++) {
			// We can replace s[0] with anything to make s[0..0] strictly increasing (SI),
			// number of replacement is always 1
			f[0][i] = 1;
		}
		g[0] = 0; // We can choose not to replace s[0] and still amek s[0..0] SI.

		for (int i = 1; i < m; i++) {
			for (int j = 0; j < n; j++) {
				// Imagine case:
				// a0 a1 a2 a3
				// b0 b1 b2 b3
				// We want to determine the replacements needed if we are to replace a3 with b3
				if (t[j] > s[i - 1]) { 
					// if b3 > a2, then we don't have to replace a2
					f[i][j] = min(g[i - 1], INT_MAX - 1) + 1;
				}
				if (j > 0) {
					// if b3 <= a2, we do have to replace a2 with b2
					// Don't be intimidated by long expression to avoid int overflow
					// The essence here is just f[i][j] = f[i - 1][j - 1] + 1 if it makes it smaller.
					f[i][j] = min(f[i][j], min(f[i - 1][j - 1], INT_MAX - 1) + 1);
				} 
				// j == 0 is the case where we want to replace a3 with b0, even if b0 <= a2, there is
				// nothing in t that we can use to replace a2, so f[i][j] will remain to be INT_MAX.
			}

			// Now we try to compute g[i]. Imagine we want to know how many replacements are needed to make
			// a0, a1, a2, a3 increasing without replacing a3
			if (s[i] > s[i - 1]) {
				// If a3 > a2, then a2 doesn't need to be replaced either
				g[i] = g[i - 1];
			} else {
				// if a3 <= a2, then a2 has to be replaced (with something smaller than a3), so ignore g[i - 1]
				g[i] = INT_MAX;
			}
			for (int j = 0; j < n; j++) {
				if (t[j] < s[i]) {
					// e. g. If b2 < a3, then replacing a2 with b2 is a valid replacement
					g[i] = min(g[i], f[i - 1][j]);
				}
			}
		}

		// Result is either replacing s[n] with t[j] for any j = 1 ~ n, or not replacing s[n] at all
		int ans = min(g[m - 1], *min_element(f[m - 1].begin(), f[m - 1].end()));
		return ans == INT_MAX ? -1 : ans;
	}
};