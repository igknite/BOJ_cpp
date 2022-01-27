#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n = 0;
	cin >> n;
	vector<pair<int, int>> vec(n);
	for (int i = 0; i < n; i++) {
		cin >> vec[i].first >> vec[i].second;
	}
	vector<int> num(n);
	for (int i = 0; i < n; i++) {
		int k = 1;
		int tall = vec[i].first;
		int weight = vec[i].second;
		for (int l = 0; l < n; l++) {
			if (i == l) continue;
			if (tall < vec[l].first && weight < vec[l].second) k++;
		}
		num[i] = k;
	}
	cout << num[0];
	for (int i = 1; i < n; i++) {
		cout << " " << num[i];
	}
	return 0;
}