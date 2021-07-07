#include<vector>
#include<iostream>

using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int level = 0;
	cin >> level;
	vector<int> v(level);
	vector<int> now(level);

	cin >> v[0];
	now[0] = v[0];

	for (int n = 1; n < level; n++) {
		for (int m = 0; m <= n; m++) {
			cin >> v[m];
		}
		for (int m = n; m >= 0; m--) {
			if (m == 0) now[m] += v[0];
			else if (m == n) now[m] = now[m - 1] + v[m];
			else now[m] = max(now[m - 1], now[m]) + v[m];
		}
	}

	int max = now[0];
	for (int n = 0; n < level; n++) {
		if (max < now[n]) max = now[n];
	}
	cout << max << endl;

	return 0;
}