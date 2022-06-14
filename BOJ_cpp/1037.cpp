#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	int num = 0;
	cin >> num;
	vector<int> factor(num);
	for (int i = 0; i < num; i++) {
		cin >> factor[i];
	}
	
	sort(factor.begin(), factor.end());
	cout << factor[0] * factor[num - 1];

	return 0;
}