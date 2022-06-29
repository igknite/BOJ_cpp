#include <iostream>
#include <vector>

using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n = 0;
	cin >> n;
	vector<int> wine(100001);
	vector<int> drink(100001);
	for (int i = 1; i <= n; i++) {
		cin >> wine[i];
	}
	drink[1] = wine[1];
	if(n >= 2) drink[2] = wine[1] + wine[2];
	
	for (int i = 3; i <= n; i++) {
		drink[i] = max(drink[i - 1], max(drink[i - 3] + wine[i - 1], drink[i - 2]) + wine[i]);
	}
	// 계단 오르기와 달리 마지막 포도주를 마시지 않아도 된다. -> 직전단계와 함께 연산해야 함.
	cout << drink[n];

	return 0;
}