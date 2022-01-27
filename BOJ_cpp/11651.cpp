#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> vec;
	int a, b;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		vec.push_back(make_pair(b, a));
	}
	sort(vec.begin(), vec.end());
	for (int i = 0; i < n; i++) {
		cout << vec[i].second << " " << vec[i].first << '\n';
	}
	return 0;
}