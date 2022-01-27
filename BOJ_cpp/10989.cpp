#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, tmp;
	cin >> n;
	vector<int> countArray(10000);
	//counting
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		countArray[tmp - 1]++;
	}

	for (int i = 0; i < 10000; i++) {
		for (int l = 0; l < countArray[i]; l++) {
			cout << i + 1 << '\n';
		}
	}

	return 0;
}